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
int label_counter=0;
FILE *asm_file;
char *main_asm;
char *data_asm;
int sp_offset;
int live_list[18];

///////////////////////////////////////////////////////////
///////////////---- emit funcs -----///////////////////
///////////////////////////////////////////////////////////
void init_codegen()
{
	int i;

	open_asm_file();

	data_asm="";
	main_asm="";
	
	live_list[0] = 1;
	live_list[1] = 1;
	for ( i=2 ; i<18 ; i++ )
		live_list[i] = 0;
}

void open_asm_file( )
{
	asm_file = fopen ( "out.s", "w" );
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

void emit_func ( char* name ) {

	main_asm = str_append ( main_asm, name );
	main_asm = str_append ( main_asm, ":\n" );

	//save registers here
	

}

void emit_var_assign ( char *name ) {

	char str[100];

	var_t *existing_var = find_var( name );
	if ( existing_var == NULL )
		sprintf ( str, "\tsw $8, %d($sp)\n", sp_offset+4 );
	else
		sprintf ( str, "\tsw $8, %d($sp)\n", existing_var->sp_offset );
	main_asm = str_append ( main_asm, str );
}

void emit_const_loadi ( int i ){

	char str[100];
	sprintf ( str, "\tli $8, %d\n", i );
	main_asm = str_append ( main_asm, str );
	
}

// FIXME: For some reason, the floating point does not get properly to this point.
//        We always get zero here, while the parser sees the actual value!!
void emit_const_loadf ( float fl ){
	char str[100];
	printf("floating point %f\n", fl);
	sprintf ( str, "\tli $8, 0x%04x\n", *((unsigned int *) &fl) );
	main_asm = str_append ( main_asm, str );

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

void push_reg_stack ( int i, char *str ) {
	if ( reg_stack == NULL ) {
		temp_reg_t *newtemp = (temp_reg_t *) malloc ( sizeof (temp_reg_t) );
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
			push_reg_stack ( i, "abc" );
			sprintf ( str, "\tmove $%d, $8\n", i + 8);
			main_asm = str_append ( main_asm, str );
			break;
		}

	if ( check == 0 ) {
		//pushing the label to stack
		sprintf ( str, "_%d_temp_reg", label_counter );
		push_reg_stack ( 0, str );

		//storing data to label in main
		sprintf ( str, "\tsw $8, _%d_temp_reg\n", label_counter );
		main_asm = str_append ( main_asm, str );
		
		//storing the label in data section
		sprintf ( str, "_%d_temp_reg:\n\t.word 0\n", label_counter );
		data_asm = str_append ( data_asm, str );

		label_counter++;
	}

}

void emit_op( int op ) {

	char str[100];
	emit_get_from_live();
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

void emit_return() {

	char str[100];
	//store the return value in $v0
	sprintf ( str, "\tmove $2, $8\n" );
	main_asm = str_append ( main_asm, str );

	//return to $ra
	sprintf ( str, "\tjr $ra\n" );
	main_asm = str_append ( main_asm, str );
	
}

void emit_func_call ( char *name, int param_count, char *type ) {

	char str[100];

	if ( strcmp ( name, "write" ) == 0 ) {
		emit_get_from_live();
		//move integer/str_address to print
		sprintf ( str, "\tmove $a0, $9\n" );
		main_asm = str_append ( main_asm, str );

		//set syscall type
		if ( strcmp(type,"string")==0 )
			sprintf ( str, "\tli $v0, 4\n" );
		else 
			sprintf ( str, "\tli $v0, 1\n" );
		main_asm = str_append ( main_asm, str );
		//call it!
		sprintf ( str, "\tsyscall\n" );
		main_asm = str_append ( main_asm, str );
	}

}

void emit_load_var( char *name ){

	char str[100];

	var_t *existing_var = find_var( name );
	if ( existing_var != NULL )
		sprintf ( str, "\tlw $8, %d($sp)\n", existing_var->sp_offset );
	main_asm = str_append ( main_asm, str );
	

}

void emit_load_string ( char *const_str ) {

	char str[100];

	//storing data to label in main
	sprintf ( str, "\tla $8, _%d_const_string\n", label_counter );
	main_asm = str_append ( main_asm, str );
		
	//storing the label in data section
	sprintf ( str, "_%d_const_string:\n\t.asciiz %s\n", label_counter, const_str );
	data_asm = str_append ( data_asm, str );

	label_counter++;

}
