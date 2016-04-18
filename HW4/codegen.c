#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"
#include "codegen.h"

temp_reg_t *reg_stack=NULL;
temp_sc_label_t *sc_stack=NULL;
int label_counter=0;
FILE *asm_file;
char *main_asm;
char *data_asm;
int sp_offset;
int live_list[18];
char t0_type[256];
char t1_type[256];
int label_no=0, label_no_global=0, label_no_local=0, label_sc_global=0;
int FP_label_no = 0;
int saved_sp_offset, saved_ra_offset;
int label_stack[10];
int i_label_stack = 0;

///////////////////////////////////////////////////////////
///////////////---- emit funcs -----///////////////////
///////////////////////////////////////////////////////////
void init_codegen( char* outname )
{
	int i;

	open_asm_file( outname );

	data_asm="";
	main_asm="";
	
	live_list[0] = 1;   //result of expr
	live_list[1] = 1;   //expr operand
	live_list[2] = 1;	//array index calculations
	for ( i=3 ; i<18 ; i++ )
		live_list[i] = 0;
}

void open_asm_file( char* outname )
{

	char str[256];
	sprintf ( str, "%s.s", outname );
	asm_file = fopen ( str, "w" );
}

void close_asm_file( )
{
	fclose( asm_file );
}

int get_sp_offset()
{
	return sp_offset;
}

void set_sp_offset( int offset )
{
	sp_offset = offset;
}

void emit_source_text( )
{
	main_asm = str_append( main_asm, "# " );
	main_asm = str_append( main_asm, get_source_text() );
	main_asm = str_append( main_asm, "\n\n" );
	init_source_text();
}

char *str_append ( char *str1, char*str2 ) {
	char * new_str ;
	if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    	new_str[0] = '\0';
    	strcat(new_str,str1);
    	strcat(new_str,str2);
	} 
	
	return new_str;
}

void emit_asm ( char *text ) {
	
	fprintf ( asm_file, "%s", text );
	
}

void print_all_asm() {

	emit_asm ( "\t.text\n" );
	emit_asm ( main_asm );
	emit_asm ( "\t.data\n" );
	emit_asm ( data_asm );

}

////////////////////////////
// Function declaration emit functions
////////////////////////////
void emit_func ( char* name ) {
	char str[100];

	main_asm = str_append ( main_asm, name );
	main_asm = str_append ( main_asm, ":\n" );

	if( strcmp( name, "main" )==0 )
	{
		// offset sp due to exception trying to read from beginning of stack
		sprintf ( str, "\tadd $sp, $sp, %d\n", -4 );
		main_asm = str_append ( main_asm, str );
	}

	// sp saved by caller right after all the parameters
	saved_sp_offset = sp_offset;
	sp_offset -= 4;

	// save ra
	sprintf ( str, "\tsw $ra, %d($sp)\n", sp_offset );
	main_asm = str_append ( main_asm, str );
	saved_ra_offset = sp_offset;
	sp_offset -= 4;

}

void emit_return( type_t ret_type ) {

	char str[100];
	// Do return type conversion
	if( strcmp(ret_type.real_type,"int")==0 && strcmp(t0_type, "float")==0 )
	{
		reg_float_to_int( 8 );
	}
	else if( strcmp(ret_type.real_type,"float")==0 && strcmp(t0_type, "int")==0 )
	{
		reg_int_to_float( 8 );
	}

	// restore return address (always at offset -4)
	sprintf ( str, "\tlw $ra, %d($sp)\n", saved_ra_offset );
	main_asm = str_append ( main_asm, str );

	//deallocate stack by restoring sp (always at offset 0)
	sprintf ( str, "\tlw $sp, %d($sp)\n", saved_sp_offset );
	main_asm = str_append ( main_asm, str );

	//store the return value in $v0
	sprintf ( str, "\tmove $2, $8\n" );
	main_asm = str_append ( main_asm, str );

	//return to $ra
	sprintf ( str, "\tjr $ra\n" );
	main_asm = str_append ( main_asm, str );
	
}

////////////////////////////
// Function call emit functions
////////////////////////////

void emit_func_call ( char *name, int param_count, char *type ) {

	char str[100];

	if ( strcmp ( name, "write" ) == 0 ) {
		emit_get_from_live();
		if( strcmp(type,"string")==0 )
		{
			//move integer/str_address to print
			sprintf ( str, "\tmove $a0, $9\n" );
			main_asm = str_append ( main_asm, str );

			//set syscall type
			sprintf ( str, "\tli $v0, 4\n" );
			main_asm = str_append ( main_asm, str );
		}
		else if( strcmp(type,"int")==0 )
		{
			//move integer/str_address to print
			sprintf ( str, "\tmove $a0, $9\n" );
			main_asm = str_append ( main_asm, str );

			//set syscall type
			sprintf ( str, "\tli $v0, 1\n" );
			main_asm = str_append ( main_asm, str );
		}
		else if( strcmp(type,"float")==0 )
		{
			// convert result to float if necessary
			if( strcmp(t1_type,"int")==0 )
			{
				reg_int_to_float( 9 );
			}
			//move result to FP register
			sprintf ( str, "\tmtc1 $9, $f12\n" );
			main_asm = str_append ( main_asm, str );

			//set syscall type
			sprintf ( str, "\tli $v0, 2\n" );
			main_asm = str_append ( main_asm, str );
		}
		
		//call it!
		sprintf ( str, "\tsyscall\n" );
		main_asm = str_append ( main_asm, str );

		// deallocate stack
		sp_offset += (4*param_count);
	}
	else if ( strcmp ( name, "read" ) == 0 ) {
		//read int
		sprintf ( str, "\tli $v0, 5\n" );
		main_asm = str_append ( main_asm, str );

		//call it!
		sprintf ( str, "\tsyscall\n" );
		main_asm = str_append ( main_asm, str );

		//move it to $8
		sprintf ( str, "\tmove $8, $v0\n" );
		main_asm = str_append ( main_asm, str );
		strcpy( t0_type, "int" );

	}
	else
	{
		// Stack frame:
		//                         |-----------------|
		// sp ->                   |  parameter 1    |
		// sp-4->                  |  parameter 2    |
		// sp-param_count->        |       sp        |
		// sp-4*param_count-4->    |       ra        |
		// sp-4*param_count-8->    |       locals    |
		//                         |-----------------|

		// parameters should be on stack already

		// 1. Save current stack pointer into calee's stack
		sprintf ( str, "\tsw $sp, %d($sp)\n", sp_offset );
		main_asm = str_append ( main_asm, str );
		set_sp_offset( get_sp_offset() - 4 );

		// 2. Set stack pointer to beginning of callee's frame
		sprintf ( str, "\tadd $sp, $sp, %d\n", (sp_offset + 4*(param_count+1)) );
		main_asm = str_append ( main_asm, str );

		// 3. jump to function (all parameters should be on the stack already)
		// we do not save any registers
		sprintf ( str, "\tjal %s\n", name );
		main_asm = str_append ( main_asm, str );

		// 4. get return value
		sprintf ( str, "\tmove $8, $2\n" );
		main_asm = str_append ( main_asm, str );
		
		// 5. Deallocate callee's stack
		sp_offset += (4*(param_count+1));
	}

}

void emit_var_assign ( type_t var_type ) {

	char str[100];
	var_t *existing_var;

	// Do type conversion
	if( strcmp(t0_type,"int")==0 && strcmp(var_type.real_type,"float")==0 )
	{
		reg_int_to_float( 8 );
	}
	else if( strcmp(t0_type,"float")==0 && strcmp(var_type.real_type,"int")==0 )
	{
		reg_float_to_int( 8 );
	}
	
	existing_var = find_var( var_type.name );
	if ( existing_var != NULL ) {
		if ( existing_var->dim > 0 ) {
			//this is an array reference, so store to $10
			sprintf ( str, "\tsw $8, 0($10)\n" );
		}
		else
		{
			// save register to stack
			sprintf ( str, "\tsw $8, %d($sp)\n", existing_var->sp_offset );
		}
	}
	else if ( existing_var == NULL )
	{
		// init list assignment. Variable not in symbol table yet
		sprintf ( str, "\tsw $8, %d($sp)\n", sp_offset+4 );
	}
	
	main_asm = str_append ( main_asm, str );
}

void emit_const_loadi ( int i ){

	char str[100];
	sprintf ( str, "\tli $8, %d\n", i );
	main_asm = str_append ( main_asm, str );
	strcpy( t0_type, "int" );
}

// FIXME: For some reason, the floating point does not get properly to this point.
//        We always get zero here, while the parser sees the actual value!!
void emit_const_loadf ( float fl ){
	char str[100];
	sprintf ( str, "\tli $8, 0x%04x\n", *((unsigned int *) &fl) );
	main_asm = str_append ( main_asm, str );
	strcpy( t0_type, "float" );
}

void emit_negate() {
	char str[100];
	sprintf ( str, "\tneg $8, $8\n" );
	main_asm = str_append ( main_asm, str );
}

void emit_not() {
	char str[100];
	sprintf ( str, "\tnot $8, $8\n" );
	main_asm = str_append ( main_asm, str );
}

temp_reg_t pop_reg_stack(){

	//last element of stack
	if ( reg_stack->next == NULL ) {
		temp_reg_t *temp=reg_stack;
		reg_stack = NULL;
		return *temp;
	}
	else {
		temp_reg_t *temp=reg_stack;
		while ( temp->next->next!=NULL ) temp = temp->next;
		temp_reg_t *temp2=temp->next;
		temp->next = NULL;
		return *temp2;		
	}
}

void push_reg_stack ( int i, char *str, char *type ) {
	if ( reg_stack == NULL ) {
		temp_reg_t *newtemp = (temp_reg_t *) malloc ( sizeof (temp_reg_t) );
		strcpy( newtemp->type, type );
		newtemp->reg = 0;
		if ( i != 0 )
			newtemp->reg = i;
		else
			strcpy ( newtemp->label, str );
		newtemp->next=NULL;
		reg_stack = newtemp;
	}
	else {
		temp_reg_t *newtemp = reg_stack;
		while ( newtemp->next != NULL ) newtemp = newtemp->next;
		newtemp->next = (temp_reg_t *) malloc ( sizeof (temp_reg_t) );
		strcpy( newtemp->next->type, type );
		newtemp->next->reg = 0;
		if ( i != 0 )
			newtemp->next->reg = i;
		else
			strcpy ( newtemp->next->label, str );
		newtemp->next->next=NULL;
	}
}

void emit_get_from_live() {

	char str[100];
	temp_reg_t temp = pop_reg_stack();
	
	// data is stored in regs
	if ( temp.reg != 0 ) {
		sprintf ( str, "\tmove $9, $%d\n", temp.reg + 8);
		live_list[temp.reg] = 0;
	}
	else
		sprintf ( str, "\tlw $9, %s\n", temp.label );

	strcpy( t1_type, temp.type );
	main_asm = str_append ( main_asm, str );

	//return temp.reg;
}

void emit_move_to_live() {

	char str[100];
	int i, check=0;
	for ( i=1 ; i<18 ; i++ )
		if ( live_list[i] == 0 ) {
			check = 1;
			live_list[i] = 1;
			push_reg_stack ( i, "abc", t0_type );
			sprintf ( str, "\tmove $%d, $8\n", i + 8);
			main_asm = str_append ( main_asm, str );
			break;
		}

	if ( check == 0 ) {
		//pushing the label to stack
		sprintf ( str, "_%d_temp_reg", label_counter );
		push_reg_stack ( 0, str, t0_type );

		//storing data to label in main
		sprintf ( str, "\tsw $8, _%d_temp_reg\n", label_counter );
		main_asm = str_append ( main_asm, str );
		
		//storing the label in data section
		sprintf ( str, "_%d_temp_reg:\n\t.word 0\n", label_counter );
		data_asm = str_append ( data_asm, str );

		label_counter++;
	}

}

void emit_save_to_stack()
{
	char str[100];

	sprintf ( str, "\tsw $8, %d($sp)\n", sp_offset);
	main_asm = str_append ( main_asm, str );
	sp_offset -= 4;
}

void emit_op( int op ) {

	char str[100];
	int fp_op = 0; // perform floating point operation?
	emit_get_from_live();

	// determine if type conversion is necessary
	// always convert from integer to float until assignment
	if( strcmp(t0_type,"int")==0 && strcmp(t1_type,"float")==0 )
	{
		reg_int_to_float( 8 );
		fp_op = 1;
	}
	else if( strcmp(t0_type,"float")==0 && strcmp(t1_type,"int")==0 )
	{
		reg_int_to_float( 9 );
		fp_op = 1;
	}
	else if( strcmp(t0_type,"float")==0 && strcmp(t1_type,"float")==0 )
	{
		fp_op = 1;
	}

	if( fp_op==0 || op==4 || op==5 )
	{
		if ( op == 0 )
			sprintf ( str, "\tmul $8, $8, $9\n" );
		else if ( op == 1 )
			sprintf ( str, "\tdiv $8, $9, $8\n" );
		else if ( op == 2 )
			sprintf ( str, "\tadd $8, $8, $9\n" );
		else if ( op == 3 )
			sprintf ( str, "\tsub $8, $9, $8\n" );
		else if ( op == 4 )
			sprintf ( str, "\tor $8, $8, $9\n" );
		else if ( op == 5 )
			sprintf ( str, "\tand $8, $9, $8\n" );
		else if ( op == 6 )
			sprintf ( str, "\tslt $8, $9, $8\n" );
		else if ( op == 7 )
			sprintf ( str, "\tsle $8, $9, $8\n" );
		else if ( op == 8 )
			sprintf ( str, "\tsgt $8, $9, $8\n" );
		else if ( op == 9 )
			sprintf ( str, "\tsge $8, $9, $8\n" );
		else if ( op == 10 )
			sprintf ( str, "\tseq $8, $9, $8\n" );
		else if ( op == 11 )
			sprintf ( str, "\tsne $8, $9, $8\n" );

		main_asm = str_append ( main_asm, str );
	}
	else
	{
		// move t0 and t1 to FP co-processor (f0, f2)
		sprintf ( str, "\tmtc1 $8, $f0\n");
		main_asm = str_append ( main_asm, str );
		sprintf ( str, "\tmtc1 $9, $f2\n" );
		main_asm = str_append ( main_asm, str );

		// perform computation
		// BUG: spim won't recognize gt, ge, and ne
		if ( op == 0 )
			sprintf ( str, "\tmul.s $f0, $f2, $f0\n" );
		else if ( op == 1 )
			sprintf ( str, "\tdiv.s $f0, $f2, $f0\n" );
		else if ( op == 2 )
			sprintf ( str, "\tadd.s $f0, $f2, $f0\n" );
		else if ( op == 3 )
			sprintf ( str, "\tsub.s $f0, $f2, $f0\n" );
		else if ( op == 6 || op == 9 )
			sprintf ( str, "\tc.lt.s $f2, $f0\n" );
		else if ( op == 7 || op == 8 )
			sprintf ( str, "\tc.le.s $f2, $f0\n" );
		//else if ( op == 8 )
		//	sprintf ( str, "\tc.gt.s $f0, $f2\n" );
		//else if ( op == 9 )
		//	sprintf ( str, "\tc.ge.s $f0, $f2\n" );
		else if ( op == 10 || op == 11)
			sprintf ( str, "\tc.eq.s $f2, $f0\n" );
		//else if ( op == 11 )
		//	sprintf ( str, "\tc.ne.s $f0, $f2\n" );

		main_asm = str_append ( main_asm, str );

		// copy f0 to t0 if arithmetic operation
		if( op==0 || op==1 || op==2 || op==3 )
		{
			sprintf ( str, "\tmfc1 $8, $f0\n" );
			main_asm = str_append ( main_asm, str );
		}
		else if( op==6 || op==7 || op==10 )
		{
			// set t0 according to FP condition flag
			sprintf ( str, "\tbc1f FP%d_clear\n", ++FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tli $8, 1\n" );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tj FP%d_exit\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "FP%d_clear:\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tli $8, 0\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "FP%d_exit:\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
		}
		else if( op==8 || op==9 || op==11 )
		{
			sprintf ( str, "\tbc1t FP%d_clear\n", ++FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tli $8, 1\n" );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tj FP%d_exit\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "FP%d_clear:\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tli $8, 0\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "FP%d_exit:\n", FP_label_no );
			main_asm = str_append ( main_asm, str );
		}	
	}
	
}

// Register d is converted from float to integer
void reg_float_to_int( int d )
{
	char str[100];

	// move d to fr0 at FP co-processor
	sprintf ( str, "\tmtc1 $%d, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// Do conversion to integer
	sprintf ( str, "\tcvt.w.s $f0, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// Move result back to d
	sprintf ( str, "\tmfc1 $%d, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// update register t0 and t1 types
	if( d==8 )
	{
		strcpy( t0_type, "int" );
	}
	else if( d==9 )
	{
		strcpy( t1_type, "int" );
	}
}

// Register d is converted from integer to float
void reg_int_to_float( int d )
{
	char str[100];

	// move d to f0 at FP co-processor
	sprintf ( str, "\tmtc1 $%d, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// Do conversion to float
	sprintf ( str, "\tcvt.s.w $f0, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// Move result back to d
	sprintf ( str, "\tmfc1 $%d, $f0\n", d );
	main_asm = str_append ( main_asm, str );

	// update register t0 and t1 types
	if( d==8 )
	{
		strcpy( t0_type, "float" );
	}
	else if( d==9 )
	{
		strcpy( t1_type, "float" );
	}
}

void emit_load_var( char *name ){

	char str[100];

	var_t *existing_var = find_var( name );
	if ( existing_var != NULL )
	{
		sprintf ( str, "\tlw $8, %d($sp)\n", existing_var->sp_offset );
		strcpy( t0_type, existing_var->type );
		main_asm = str_append ( main_asm, str );
	}

}

void emit_load_string ( char *const_str ) {

	char str[100];

	//storing data to label in main
	sprintf ( str, "\tla $8, _%d_const_string\n", label_counter );
	strcpy( t0_type, "string" );
	main_asm = str_append ( main_asm, str );
		
	//storing the label in data section
	sprintf ( str, "_%d_const_string:\n\t.asciiz %s\n", label_counter, const_str );
	data_asm = str_append ( data_asm, str );

	label_counter++;

}

void inc_loop_label()
{
	label_no++;
	i_label_stack++;
	label_stack[i_label_stack] = label_no;
}

void dec_loop_label()
{
	i_label_stack--;
}

int inc_sc_label()
{
	return label_sc_global++;
}

void dec_sc_label()
{
	label_sc_global--;
}

void gen_head()
{
	char str[100];

	inc_loop_label();

	sprintf ( str, "_Test%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_test_if()
{
	char str[100];

	sprintf ( str, "\tbeqz $8, _Lexit_or_else%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_label_if_else()
{
	char str[100];

	sprintf ( str, "\tj _Lexit%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "_Lexit_or_else%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_label_exit_if()
{
	char str[100];

	sprintf ( str, "_Lexit_or_else%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );

	dec_loop_label();
}

void gen_label_exit_if_else()
{
	char str[100];

	sprintf ( str, "_Lexit%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );

	dec_loop_label();
}


void gen_test_while()
{
	char str[100];

	sprintf ( str, "\tbeqz $8, _Lexit%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_label_exit_while()
{
	char str[100];

	sprintf ( str, "\tj _Test%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "_Lexit%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );

	dec_loop_label();
}

void gen_test_for()
{
	char str[100];

	sprintf ( str, "\tbeqz $8, _Lexit%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "\tj _Body%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "_Inc%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_label_for()
{
	char str[100];

	sprintf ( str, "\tj _Test%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "_Body%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
}

void gen_label_exit_for()
{
	char str[100];

	sprintf ( str, "\tj _Inc%d\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );
	sprintf ( str, "_Lexit%d:\n", label_stack[i_label_stack] );
	main_asm = str_append ( main_asm, str );

	dec_loop_label();
}

void emit_adjust_dimm( char *name ) {

	char str[100];

	var_t *existing_var = find_var( name );
	if ( existing_var != NULL )
	{
		//load the base address to $10
		sprintf ( str, "\tla $10, %d($sp)\n", existing_var->sp_offset );
		main_asm = str_append ( main_asm, str );

		int ndim = existing_var->dim, i;
		for ( i=ndim-1 ; i>=0 ; i-- ) {
			//get the index value
			emit_get_from_live();

			//multiply it by dimm size
			sprintf ( str, "\tli $8, %d\n", existing_var->arr_dimms[i] );
			main_asm = str_append ( main_asm, str );
			sprintf ( str, "\tmul $8, $8, $9\n" );
			main_asm = str_append ( main_asm, str );
			
			//subtract it from the base address
			sprintf ( str, "\tsub $10, $10, $8\n" );
			main_asm = str_append ( main_asm, str );
		}
		
		//finally, loading from the calculated address in $10
		sprintf ( str, "\tlw $8, 0($10)\n" );
		strcpy( t0_type, existing_var->type );
		main_asm = str_append ( main_asm, str );

	}

}

///////////////////////////////////////////////////////////////////////
/////////////////////   SHORT-CIRCUIT Funcs  //////////////////////////
///////////////////////////////////////////////////////////////////////

int pop_sc_stack(){

	//last element of stack
	if ( sc_stack->next == NULL ) {
		temp_sc_label_t *temp=sc_stack;
		sc_stack = NULL;
		return temp->label;
	}
	else {
		temp_sc_label_t *temp=sc_stack;
		while ( temp->next->next!=NULL ) temp = temp->next;
		temp_sc_label_t *temp2=temp->next;
		temp->next = NULL;
		return temp2->label;		
	}
}

void push_sc_stack ( int i ) {
	if ( sc_stack == NULL ) {
		temp_sc_label_t *newtemp = (temp_sc_label_t *) malloc ( sizeof (temp_sc_label_t) );
		newtemp->label = i;
		newtemp->next=NULL;
		sc_stack = newtemp;
	}
	else {
		temp_sc_label_t *newtemp = sc_stack;
		while ( newtemp->next != NULL ) newtemp = newtemp->next;
		newtemp->next = (temp_sc_label_t *) malloc ( sizeof (temp_sc_label_t) );
		newtemp->next->label = i;
		newtemp->next->next=NULL;
	}
}

void emit_and_sc_test() {

	char str[100];
	int sc_label = inc_sc_label();

	//emit the beqz
	sprintf ( str, "\tbeqz $8, _short_F%d\n", sc_label);
	main_asm = str_append ( main_asm, str );

	push_sc_stack(sc_label);

	

}
void emit_and_sc_tail(){

	char str[100];
	int sc_label = pop_sc_stack();
	
	//emit the beqz
	sprintf ( str, "\tbeqz $8, _short_F%d\n", sc_label);
	main_asm = str_append ( main_asm, str );

	//emit li 1
	sprintf ( str, "_short_T%d:\n\tli $8, 1\n", sc_label);
	main_asm = str_append ( main_asm, str );
	strcpy( t0_type, "int" );
	
	//J to exit
	sprintf ( str, "\tj _short_E%d\n", sc_label);
	main_asm = str_append ( main_asm, str );
	
	//Start the Failure
	sprintf ( str, "_short_F%d:\n\tli $8, 0\n_short_E%d:\n", sc_label, sc_label);
	main_asm = str_append ( main_asm, str );

}

void emit_or_sc_test() {

	char str[100];
	int sc_label = inc_sc_label();

	//emit the beqz
	sprintf ( str, "\tbnez $8, _short_T%d\n", sc_label);
	main_asm = str_append ( main_asm, str );

	push_sc_stack(sc_label);

	

}
void emit_or_sc_tail() {

	char str[100];
	int sc_label = pop_sc_stack();
	
	//emit the beqz
	sprintf ( str, "\tbnez $8, _short_T%d\n", sc_label);
	main_asm = str_append ( main_asm, str );

	//emit li 1
	sprintf ( str, "_short_F%d:\n\tli $8, 0\n", sc_label);
	main_asm = str_append ( main_asm, str );
	strcpy( t0_type, "int" );
	
	//J to exit
	sprintf ( str, "\tj _short_E%d\n", sc_label);
	main_asm = str_append ( main_asm, str );
	
	//Start the Failure
	sprintf ( str, "_short_T%d:\n\tli $8, 1\n_short_E%d:\n", sc_label, sc_label);
	main_asm = str_append ( main_asm, str );

}

