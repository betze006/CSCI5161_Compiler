#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"
#include "codegen.h"

type_t *type_ll=NULL;
var_t *var_ll=NULL;
func_t *func_ll=NULL;
structs_t *structs_ll=NULL;
char struct_type[256];
char random_name[256];
char source_text[4096];


//======================================================
//------------------   FUNC DEFS    --------------------
//======================================================
/**********************************
** Souce Code
***********************************/
void init_source_text()
{
	int i;
	for( i=0; i<4096; i++)
	{
		source_text[i] = 0;
	}
}

void append_source_text( char *text )
{
	strcat( source_text, text );
	free( text );
}

char *get_source_text( )
{
	return source_text;
}

/**********************************
** VARS
***********************************/
void print_vars() {

	var_t *var_pointer = var_ll;

	printf ("------------  Variables ------------\n");
	
	//writing all the variables
	while ( var_pointer != NULL ) {
		printf ( "ID=%s, TYPE=%s, DIM=%d NEST=%d\n", var_pointer->name
				, var_pointer->type, var_pointer->dim, var_pointer->nest_level );
		var_pointer = var_pointer->next;
	}

}

void add_var ( char *type, char *name, int dim, int nest_level, int sp_offset_local ) {
	if ( var_ll == NULL ) {
		var_t *var_pointer;
		//adding the new variable
		var_ll = (var_t *) malloc ( sizeof (var_t) );
		var_pointer = var_ll;
	
		//writing the values
		strcpy(var_pointer->type, type);
		strcpy(var_pointer->name, name);
		var_pointer->nest_level = nest_level;
		var_pointer->dim = dim;
		var_pointer->sp_offset = sp_offset_local;
		var_pointer->next = NULL;
	}
	else {

		//finding the next available place in variables LL
		var_t *var_pointer = var_ll;
		while ( var_pointer->next != NULL ) 
			var_pointer = var_pointer->next;
		//adding the new variable
		var_pointer->next = (var_t *) malloc ( sizeof (var_t) );
		var_pointer = var_pointer->next;
	
		//writing the values
		strcpy(var_pointer->type, type);
		strcpy(var_pointer->name, name);
		var_pointer->nest_level = nest_level;
		var_pointer->dim = dim;
		var_pointer->sp_offset = sp_offset_local;
		var_pointer->next = NULL;
	}
}

int total_num_vars()
{
	int count = 0;
	var_t *var_pointer = var_ll;
	while( var_pointer != NULL )
	{
		count++;
		var_pointer = var_pointer->next;
	}
	return count;
}

void pop_vars ( int nest_level )
{
	var_t *var_pointer = var_ll;
	var_t *next_var_pointer=NULL, *prev_var_pointer=var_ll;
	// traverse list from beginning
	while( var_pointer != NULL )
	{
		// find the point where we enter the current nesting level
		if( var_pointer->nest_level >= nest_level )
		{
			// if removing first node then set linked list to empty
			if( prev_var_pointer == var_ll )
			{
				var_ll = NULL;
			}

			prev_var_pointer->next = NULL;
	
			// now we have two detached linked lists. Free the second one
			while( var_pointer != NULL )
			{
				next_var_pointer = var_pointer->next;
				free( var_pointer );
				var_pointer = next_var_pointer;
			}
			break;
		}
		else
		{
			prev_var_pointer = var_pointer;
			var_pointer = var_pointer->next;
		}
	}
}

void cleanup_idlist ( id_list_t *head ) {
}

void add_var_list ( char *type, id_list_t *head, int nest_level ) {

	char real_type[256];
	strcpy ( real_type, type );
	
	//finding the real_type of the type (if exists)
	type_t *temp = type_ll;
	while ( temp!=NULL ) {
		if ( strcmp(temp->name, type) == 0 ) {
			strcpy ( real_type, temp->real_type );
			break;
		}
		temp = temp->next;
	}

	add_var ( real_type, head->name, head->dim, nest_level, head->sp_offset );
	while ( head->next != NULL ) {
		head = head->next;
		add_var ( real_type, head->name, head->dim, nest_level, head->sp_offset );
	}
	//cleanup_idlist ( head );
}

// returns the last (highest nesting level) ID node that matches the name
// returns NULL if not found
var_t* find_var( char *name )
{
	var_t *var_pointer = var_ll;
	var_t *var_result = NULL;
	while( var_pointer != NULL )
	{
		if( strcmp( var_pointer->name, name ) == 0 )
		{
			var_result = var_pointer;
		}
		var_pointer = var_pointer->next;
	}
	return var_result;
}

decl_list_t *get_vars_nest( int nest_level )
{
	decl_list_t *return_list=NULL;
	decl_list_t *pointer_decl_list=NULL;
	decl_list_t *new_list_node=NULL;
	var_t *pointer_var=var_ll;

	while( pointer_var!=NULL )
	{
		if( pointer_var->nest_level==nest_level )
		{
			new_list_node = (decl_list_t *)malloc(sizeof(decl_list_t));
			strcpy(new_list_node->var.name, pointer_var->name);
			strcpy(new_list_node->var.type, pointer_var->type);
			new_list_node->var.dim = pointer_var->dim;
			new_list_node->var.nest_level = pointer_var->nest_level;
			new_list_node->next = NULL;
			if( return_list==NULL )
			{
				return_list = new_list_node;
			}
			if( pointer_decl_list == NULL )
			{
				pointer_decl_list = new_list_node;
			}
			else
			{
				pointer_decl_list->next = new_list_node;
				pointer_decl_list = pointer_decl_list->next;
			}
		}
		pointer_var = pointer_var->next;
	}
	return return_list;
}

id_list_t *newIDnode(char* name, int dim){

	id_list_t *temp = (id_list_t*) malloc ( sizeof(id_list_t) );
	strcpy(temp->name, name);
	temp->dim = dim;
	temp->next = NULL;
	temp->sp_offset = get_sp_offset();
	set_sp_offset( get_sp_offset() - 4 );
	return temp;

}

/**********************************
** TYPES
***********************************/
void init_types () {

	type_ll = (type_t *) malloc ( sizeof(type_t) );
	strcpy(type_ll->name, "int");
	strcpy(type_ll->real_type, "int");
	type_ll->nest_level = 0;
	type_ll->next = (type_t *) malloc ( sizeof(type_t) );
	strcpy(type_ll->next->name, "float");
	strcpy(type_ll->next->real_type, "float");
	type_ll->next->nest_level = 0;
	type_ll->next->next = NULL;

}

void print_types () {

	type_t *temp = type_ll;

	printf ("------------  Types ------------\n");
	while ( temp!=NULL ) 
	{
		printf ("TYPE=%s, OrigType=%s, NEST=%d\n"
				, temp->name, temp->real_type, temp->nest_level );
		temp = temp->next;
	}
}

void type_def ( char *type, id_list_t *head, int nest_level ) {
	type_t *temp = type_ll;
	while ( temp->next!=NULL ) 
		temp = temp->next;

	temp->next = (type_t *) malloc ( sizeof(type_t) );
	temp = temp->next;
	strcpy(temp->name, head->name);
	strcpy(temp->real_type, type);
	temp->nest_level = nest_level;
	temp->next = NULL;

	while ( head->next != NULL ) {
		head = head->next;
		temp->next = (type_t *) malloc ( sizeof(type_t) );
		temp = temp->next;
		strcpy(temp->name, head->name);
		strcpy(temp->real_type, type);
		temp->nest_level = nest_level;
		temp->next = NULL;
	} 
}

void pop_types ( int nest_level )
{
	type_t *type_pointer = type_ll;
	type_t *next_type_pointer=NULL, *prev_type_pointer=type_ll;

	// traverse list from beginning
	while( type_pointer != NULL )
	{
		// find the point where we enter the current nesting level
		if( type_pointer->nest_level >= nest_level )
		{
			// if removing first node then set linked list to NULL
			if( prev_type_pointer == type_ll )
			{
				type_ll = NULL;
			}

			prev_type_pointer->next = NULL;

			// now we have two detached linked lists. Free the second one
			while( type_pointer != NULL )
			{
				next_type_pointer = type_pointer->next;
				free( type_pointer );
				type_pointer = next_type_pointer;
			}
			break;
		}
		else
		{
			prev_type_pointer = type_pointer;
			type_pointer = type_pointer->next;
		}
	}
}

char *get_real_type( char *type )
{
	char *real_type=NULL;
	type_t *type_pointer=type_ll;
	while( type_pointer!=NULL )
	{
		if( strcmp( type_pointer->name, type )==0 )
		{
			real_type = type_pointer->real_type;
			break;
		}
		type_pointer = type_pointer->next;
	}
	return real_type;
}

void init_funcs () {

	func_ll = (func_t *) malloc ( sizeof (func_t) );
	strcpy(func_ll->name, "write");
	strcpy(func_ll->type, "void");
	func_ll->params = (param_list_t *) malloc ( sizeof(param_list_t) );
	func_ll->params->next=NULL;
	strcpy(func_ll->params->param.name, "arg1");
	strcpy(func_ll->params->param.type, "int");
	func_ll->next = (func_t *) malloc ( sizeof(func_t) );
	strcpy(func_ll->next->name, "read");
	strcpy(func_ll->next->type, "int");
	func_ll->next->params=NULL;
	func_ll->next->next = (func_t *) malloc ( sizeof(func_t) );
	strcpy(func_ll->next->next->name, "fread");
	strcpy(func_ll->next->next->type, "int");
	func_ll->next->next->params=NULL;
	func_ll->next->next->next=NULL;

}

void init_all(){
	init_source_text();
	init_types();
	init_funcs();
	init_codegen();	
}

/**********************************
** FUNCTIONS
***********************************/
void add_func ( char *type, char *name, param_list_t *params ) {

	if ( func_ll == NULL ) {
		func_t *func_pointer;
		//adding the new function
		func_ll = (func_t *) malloc ( sizeof (func_t) );
		func_pointer = func_ll;
	
		//writing the values
		strcpy(func_pointer->type, type);
		strcpy(func_pointer->name, name);
		func_pointer->params = params;
		func_pointer->next = NULL;
	}
	else {

		//finding the next available place in functions LL
		func_t *func_pointer = func_ll;
		while ( func_pointer->next != NULL ) 
			func_pointer = func_pointer->next;
		//adding the new function
		func_pointer->next = (func_t *) malloc ( sizeof (func_t) );
		func_pointer = func_pointer->next;
	
		//writing the values
		strcpy(func_pointer->type, type);
		strcpy(func_pointer->name, name);
		func_pointer->params = params;
		func_pointer->next = NULL;
	}
}


/* find function in function table and return its semantic record */
/* returns NULL if not found */
func_t* find_func( char *name )
{
	func_t *func_pointer = func_ll;
	func_t *func_result = NULL;
	while( func_pointer != NULL )
	{
		if( strcmp( func_pointer->name, name ) == 0 )
		{
			func_result = func_pointer;
		}
		func_pointer = func_pointer->next;
	}
	return func_result;
}

/* Last function is the current function declaration being parsed */
func_t* find_last_func( )
{
	func_t *func_pointer = func_ll;

	while( func_pointer->next != NULL )
		func_pointer = func_pointer->next;

	return func_pointer;
}

int get_num_params( func_t *func )
{
	int count = 0;
	param_list_t *param_pointer;
	while( param_pointer != NULL )
	{
		count++;
		param_pointer = param_pointer->next;
	}
	return count;
}

param_list_t *newParamNode(char* type, char* name, int dim, int nest_level){

	param_list_t *temp = (param_list_t*) malloc ( sizeof(param_list_t) );
	strcpy(temp->param.type, type);
	strcpy(temp->param.name, name);
	temp->param.dim = dim;
	temp->param.nest_level = nest_level;
	temp->next = NULL;
	return temp;

}

void print_funcs() {

	func_t *func_pointer = func_ll;
	param_list_t *param_pointer = NULL;

	printf ("------------  Functions ------------\n");
	
	//writing all the functions
	while ( func_pointer != NULL ) {
		printf ( "FUNC: ID=%s, TYPE=%s\n", func_pointer->name, func_pointer->type );
		param_pointer = func_pointer->params;
		while( param_pointer != NULL )
		{
			printf("\tPARAM: ID:%s, TYPE=%s, DIM:%d\n", param_pointer->param.name, param_pointer->param.type, param_pointer->param.dim);
			param_pointer = param_pointer->next;
		}
		func_pointer = func_pointer->next;
	}

}

/**********************************
** STRUCTS
***********************************/
void add_struct ( char *name, decl_list_t *members ) {
	if ( structs_ll == NULL ) {
		structs_t *structs_pointer;
		//adding the new struct
		structs_ll = (structs_t *) malloc ( sizeof (structs_t) );
		structs_pointer = structs_ll;
	
		//writing the values
		strcpy(structs_pointer->name, name);
		structs_pointer->members = members;
		structs_pointer->next = NULL;
	}
	else {

		//finding the next available place in structs LL
		structs_t *structs_pointer = structs_ll;
		while ( structs_pointer->next != NULL ) 
			structs_pointer = structs_pointer->next;
		//adding the new struct
		structs_pointer->next = (structs_t *) malloc ( sizeof (structs_t) );
		structs_pointer = structs_pointer->next;
	
		//writing the values
		strcpy(structs_pointer->name, name);
		structs_pointer->members = members;
		structs_pointer->next = NULL;
	}
}


/* find struct in structs table and return its semantic record */
/* returns NULL if not found */
structs_t* find_struct( char *name )
{
	structs_t *structs_pointer = structs_ll;
	structs_t *structs_result = NULL;

	while( structs_pointer != NULL )
	{
		if( strcmp( structs_pointer->name, name ) == 0 )
		{
			structs_result = structs_pointer;
		}
		structs_pointer = structs_pointer->next;
	}
	return structs_result;
}

void print_structs() {

	structs_t *structs_pointer = structs_ll;
	decl_list_t *member_pointer = NULL;

	printf ("------------  Structs ------------\n");
	
	//writing all the functions
	while ( structs_pointer != NULL ) {
		printf ( "STRUCT: ID=%s\n", structs_pointer->name );
		member_pointer = structs_pointer->members;
		while( member_pointer != NULL )
		{
			printf("\tMEMBER: ID:%s, TYPE=%s, DIM:%d\n", member_pointer->var.name, member_pointer->var.type, member_pointer->var.dim);
			member_pointer = member_pointer->next;
		}
		structs_pointer = structs_pointer->next;
	}
}

/* Following function takes the struct name and returns a string 'struct name' which will be a new type */
char *build_struct_type( char *name )
{
	int i;
	if( name==NULL )
	{
		return NULL;
	}
	// init array
	for( i=0; i<256; i++ )
	{
		struct_type[i] = 0;
	}
	strcat( struct_type, "struct ");
	strcat( struct_type, name);
	return struct_type;
}

char *get_random_name( )
{
	int i;
	for( i=0; i<256; i++ )
	{
		random_name[i] = 0;
	}
	sprintf(random_name, "%d", get_linenumber() );
	return random_name;
}

decl_list_t *id_list_to_decl_list( char *type, id_list_t *id_list, int nest_level )
{
	decl_list_t *head_decl_list=NULL;
	decl_list_t *tail_decl_list=NULL;
	decl_list_t *new_decl_list_node=NULL;

	while( id_list != NULL )
	{
		// populate new node
		new_decl_list_node = (decl_list_t *)malloc(sizeof(decl_list_t));
		strcpy(new_decl_list_node->var.name, id_list->name);
		strcpy(new_decl_list_node->var.type, type);
		new_decl_list_node->var.dim = id_list->dim;
		new_decl_list_node->var.nest_level = nest_level;
		new_decl_list_node->next = NULL;
		
		// add node to list
		if( head_decl_list==NULL )
		{
			// first node
			head_decl_list = new_decl_list_node;
			tail_decl_list = new_decl_list_node;
		}
		else
		{
			tail_decl_list->next = new_decl_list_node;
			tail_decl_list = tail_decl_list->next;
		}

		id_list = id_list->next;
	}
	return head_decl_list;
}

void append_decl_list_to_var( decl_list_t *decl_list )
{
	while( decl_list!=NULL )
	{
		add_var( decl_list->var.type, decl_list->var.name, decl_list->var.dim, decl_list->var.nest_level, 1000 );
		decl_list = decl_list->next;
	}
}

decl_list_t *cat_decl_lists( decl_list_t *list1, decl_list_t *list2 )
{
	decl_list_t *cur_node=list1;
	decl_list_t *next_node;
	if( cur_node!=NULL )
	{
		while( cur_node->next!=NULL )
		{
			//cur_node = next_node;
			cur_node = cur_node->next;
		}
		cur_node->next = list2;
	}
	else
	{
		list1 = list2;
	}
	return list1;
}

decl_list_t *find_struct_member( structs_t *var_struct, char *name )
{
	decl_list_t *member_pointer=var_struct->members;
	decl_list_t *return_member=NULL;

	while( member_pointer!=NULL )
	{
		if( strcmp( member_pointer->var.name, name ) == 0 )
		{
			return_member = member_pointer;
			break;
		}
		member_pointer = member_pointer->next;
	}

	return return_member;
}

