#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"

temp_reg_t *reg_stack=NULL;
int label_counter=0;

//======================================================
//------------------   FUNC DEFS    --------------------
//======================================================
id_list_t *var_decl (char* name, int dim)
{
	// Check if variable already exists in current nesting level
	var_t *existing_var = find_var( name );
	if( existing_var != NULL && existing_var->nest_level==get_nesting() )
	{
		print_current_line();
		printf( "\tID (%s) redeclared.\n", name );
		inc_errors();
	}
	return newIDnode( name, dim );
}

void process_id( char *name )
{
	// Check if id is declared
	var_t *existing_var = find_var( name );
	if( existing_var == NULL )
	{
		print_current_line();
		printf( "\tID (%s) undeclared.\n", name );
		inc_errors();
	}
}

param_list_t *func_param_decl (char* type, char* name, int dim, int nest_level)
{
	add_var(type, name, dim, nest_level, 0);
	return newParamNode(type, name, dim, nest_level);
}

void func_decl ( char *type, char *name, param_list_t *params )
{

	//set sp offset of variables to 0
	sp_offset = -4;

	func_t* func_pointer = find_func( name );
	
	if ( func_pointer != NULL ) {
		print_current_line();
		printf( "\tFunc ID (%s) redeclared.\n", name );
		inc_errors();
	}
	else
		add_func ( type, name, params );
	
	emit_func ( &main_asm, name );

}

param_list_t *struct_param_decl (char* type, char* name, int dim, int nest_level)
{
	return newParamNode(type, name, dim, nest_level);
}

void struct_decl ( char *name )
{
	decl_list_t *members=NULL;
	decl_list_t *member_pointer=NULL;
	decl_list_t *member_pointer_2=NULL;
	char *struct_type_name=NULL;
	id_list_t *struct_var = (id_list_t *)malloc(sizeof(id_list_t));

	struct_type_name = build_struct_type( name ); // struct type is 'struct name'

	// The members of the struct are all the variable definitions in the current nesting level
	members = get_vars_nest( get_nesting() );

	// Check for duplicate members
	member_pointer = members;
	member_pointer_2 = members;
	while( member_pointer!=NULL )
	{
		member_pointer_2 = member_pointer->next;
		while( member_pointer_2!=NULL )
		{
			if( strcmp( member_pointer->var.name, member_pointer_2->var.name )==0 )
			{
				printf("In struct '%s' line %d:\n", name, get_linenumber() );
				printf( "\tDuplicate member (%s).\n", member_pointer->var.name );
			}
			member_pointer_2 = member_pointer_2->next;
		}
		member_pointer = member_pointer->next;
	}
				
	// Check for reference to struct inside struct
	member_pointer = members;
	while( member_pointer!=NULL )
	{
		if( strcmp( member_pointer->var.type, struct_type_name ) == 0 )
		{
			printf("In struct '%s' line %d:\n", name, get_linenumber() );
			printf( "\tfield (%s) has incomplete type.\n", member_pointer->var.name );
			inc_errors();
		}
		member_pointer = member_pointer->next;
	}

	// Finally add new struct to linked list
	add_struct ( name, members );

	// Add struct as a new type
	strcpy(struct_var->name, struct_type_name);
	struct_var->dim = 0; 
	struct_var->next = NULL;
	type_def( struct_type_name, struct_var, get_nesting()-1 );
}

type_t struct_ref ( char *struct_var_name, char *member_name )
{
	var_t *existing_var=NULL;
	char *var_type=NULL;
	structs_t *var_struct=NULL;
	decl_list_t *struct_member=NULL;
	
	type_t return_type;
	
	// check that variable is defined
	existing_var = find_var( struct_var_name );
	if( existing_var == NULL )
	{
		print_current_line();
		printf( "\tID (%s) redeclared.\n", struct_var_name );
		inc_errors();
	}
	// get the struct name (it's the real type in type definitions)
	else
		var_type = get_real_type( existing_var->type );

	if( var_type==NULL )
	{
		print_current_line();
		printf( "\tID (%s) type undefined.\n", struct_var_name );
		inc_errors();
	}
	else
		var_struct = find_struct( &var_type[7] );
		
	if( var_struct==NULL )
	{
		print_current_line();
		printf( "\tID (%s) struct undefined.\n", struct_var_name );
		inc_errors();
	}
	else
		struct_member = find_struct_member( var_struct, member_name );
		
	if( struct_member==NULL )
	{
		print_current_line();
		printf( "\tStructure has no member named (%s).\n", member_name );
		inc_errors();
	}
	
	if ( struct_member != NULL )
		strcpy(return_type.real_type, struct_member->var.type);
	else
		strcpy(return_type.real_type, "#$%");
	
	strcpy(return_type.name,member_name);
		
	return return_type;

}

type_t check_func_call ( char *name, int param_count ) {

	//looking for the function name
	func_t* func_pointer = find_func( name );

	type_t return_type;
	
	if ( func_pointer == NULL ) {
		print_current_line();
		printf( "\tFunc ID (%s) undeclared.\n", name );
		inc_errors();
		
	}
	else {
	
		strcpy(return_type.real_type, func_pointer->type);
	
		param_list_t *temp_param_pointer = func_pointer->params;
		int count = 1;
		if ( temp_param_pointer == NULL )
			count = 0;
		else while ( temp_param_pointer->next != NULL ) {
			count++;
			temp_param_pointer = temp_param_pointer->next;
		}
	
		if ( count < param_count ) {
			print_current_line();
			printf( "\ttoo many arguments to function (%s)\n", name );
			inc_errors();
		}
		else if ( count > param_count ) {
			print_current_line();
			printf( "\ttoo few arguments to function (%s)\n", name );
			inc_errors();
		}

	}

	return return_type;
	
}

type_t check_id_type( char *name )
{
	// Check if id is declared
	var_t *existing_var = find_var( name );
	type_t return_type;
	
	if ( existing_var != NULL ) {
		strcpy(return_type.real_type, existing_var->type);
		strcpy(return_type.name, existing_var->name);
	}
	else {
		strcpy(return_type.real_type, "#$%");
		strcpy(return_type.name, "#$%");
	}
		
	return return_type;
	
}

void check_op_types ( type_t a, type_t b) {

	char strtempa[7],strtempb[7];
	strncpy ( strtempa, a.real_type, 6 );
	strncpy ( strtempb, b.real_type, 6 );
	
	if ( (strcmp(a.real_type,"int")==0) || (strcmp(a.real_type,"float")==0) ) {
		if ( (strcmp(b.real_type,"int")!=0) && (strcmp(b.real_type,"float")!=0) ) {
			print_current_line();
			printf( "\tIncompatible return type.\n" );
			inc_errors();

		}
	}
	//TODO check the struct type!!
	else if ( (strcmp(strtempa,"struct")==0) || (strcmp(strtempb,"struct")==0) ) {
		print_current_line();
		printf( "\tInvalid operands\n" );
		inc_errors();
	}
	else if ( strcmp(a.real_type,b.real_type)!=0 ) {
		print_current_line();
		printf( "\tIncompatible operands\n" );
		inc_errors();
	}
}

void check_assign_types ( type_t a, type_t b) {

	char strtempa[7],strtempb[7];
	strncpy ( strtempa, a.real_type, 6 );
	strncpy ( strtempb, b.real_type, 6 );
	
	if ( (strcmp(a.real_type,"int")==0) || (strcmp(a.real_type,"float")==0) ) {
		if ( (strcmp(b.real_type,"int")!=0) && (strcmp(b.real_type,"float")!=0) ) {
			print_current_line();
			printf( "\tIncompatible type.\n" );
			inc_errors();

		}
	}
	else if ( strcmp(a.real_type,b.real_type)!=0 ) {
		print_current_line();
		printf( "\tIncompatible type.\n" );
		inc_errors();
	}
}

void check_func_return ( type_t ret_type ) {

	//looking for the function name
	func_t* func_pointer = find_last_func( );

	if ( (strcmp(ret_type.real_type,"int")==0) || (strcmp(ret_type.real_type,"float")==0) ) {
		if ( (strcmp(func_pointer->type,"int")!=0) && (strcmp(func_pointer->type,"float")!=0) ) {
			print_current_line();
			printf( "\tIncompatible return type.\n" );
			inc_errors();

		}
	}
	else if ( strcmp(ret_type.real_type,func_pointer->type)!=0 ) {
		print_current_line();
		printf( "\tIncompatible return type.\n" );
		inc_errors();
	}

}

void check_array_dimmension ( type_t id ) {

	int existing_var_dim;
	var_t *existing_var = find_var( id.name );
	
	if ( id.dim_count_struct >= 0 ) {
		existing_var_dim = id.dim_count_struct;
		if ( (existing_var_dim != id.param_count) ) {
			print_current_line();
			if ( existing_var_dim == 0 )
				printf( "\tScalar (%s) passed to array parameter.\n", id.name );
			else if ( id.param_count == 0 )
				printf( "\tArray (%s) passed to scalar parameter.\n", id.name );

			else
				printf( "\tIncompatible array dimensions.\n" );
			inc_errors();
		}
	}
	else if (existing_var != NULL) {
		existing_var_dim = existing_var->dim;
	
		if ( (existing_var != NULL) && (existing_var_dim != id.param_count) ) {
			print_current_line();
			if ( existing_var_dim == 0 )
				printf( "\tScalar (%s) passed to array parameter.\n", id.name );
			else if ( id.param_count == 0 )
				printf( "\tArray (%s) passed to scalar parameter.\n", id.name );

			else
			printf( "\tIncompatible array dimensions.\n" );
			inc_errors();
		}
	}
}		

int array_dimmension_struct ( type_t id , char *var_name ) {

	var_t *existing_var = find_var( var_name );
	structs_t *var_struct = find_struct( &existing_var->type[7] );

	decl_list_t *struct_member=NULL;
	struct_member = find_struct_member( var_struct, id.name );	

	if ( struct_member != NULL ) 
		return struct_member->var.dim;
	else
		return -1;

}		

void check_dim_type ( type_t dim_type ) {

	if ( strcmp(dim_type.real_type,"int") != 0 ) {
		print_current_line();
		printf( "\tArray subscript is not an integer\n" );
		inc_errors();
	}
}		


////////////////////////////////////////////////////////////////////
//////////////////////////  emit funcs  ////////////////////////////
////////////////////////////////////////////////////////////////////

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

	return temp.reg;
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
