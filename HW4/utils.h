#ifndef UTILS_H
#define UTILS_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct id_list {
	char name[256];
	struct id_list *next;
	int dim;
} id_list_t;

typedef struct var {
	char name[256];
	char type[256];
	int nest_level;
	int dim;
	struct var *next;
} var_t;

typedef struct type {
	char name[256];
	int nest_level;
	struct type *next;
	char real_type[256];
} type_t;

static int nesting = 0;
type_t *type_ll=NULL;
var_t *var_ll=NULL;

//======================================================
//------------------   FUNC DEFS    --------------------
//======================================================

void print_vars() {

	var_t *var_pointer = var_ll;
	
	//writing all the variables
	while ( var_pointer != NULL ) {
		printf ( "ID=%s, TYPE=%s, DIM=%d NEST=%d\n", var_pointer->name
				, var_pointer->type, var_pointer->dim, var_pointer->nest_level );
		var_pointer = var_pointer->next;
	}

}

void add_var ( char *type, char *name, int dim, int nest_level ) {

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
	}
}

void pop_vars ( int nest_level )
{
	var_t *var_pointer = var_ll;
	var_t *next_var_pointer;
	// traverse list from beginning
	while( var_pointer->next != NULL )
	{
		// find the point where we enter the current nesting level
		if( var_pointer->next->nest_level < nest_level )
		{
			var_pointer = var_pointer->next;
		}
		else
		{
			// next node is at the requested nesting level, so remove everything from this point on
			next_var_pointer = var_pointer->next;
			var_pointer->next = NULL;
			// now we have two detached linked lists. Free the second one
			while( next_var_pointer != NULL )
			{
				var_pointer = next_var_pointer;
				next_var_pointer = var_pointer->next;
				free( var_pointer );
			}
			break;
		}
	}	
}

void cleanup_idlist ( id_list_t *head ) {
}

void add_var_list ( char *type, id_list_t *head, int nest_level ) {

	add_var ( type, head->name, head->dim, nest_level );
	while ( head->next != NULL ) {
		head = head->next;
		add_var ( type, head->name, head->dim, nest_level );
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
		else
		{
			var_pointer = var_point->next;
		}
	}
	return var_result;
}

id_list_t *newIDnode(char* name, int dim){

	id_list_t *temp = (id_list_t*) malloc ( sizeof(id_list_t) );
	strcpy(temp->name, name);
	temp->dim = dim;
	temp->next = NULL;
	return temp;

}

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
	printf ("------------  Types ------------\nTYPE=%s, OrigType=%s, NEST=%d\n"
				, temp->name, temp->real_type, temp->nest_level );
	while ( temp->next!=NULL ) {
		temp = temp->next;
		printf ("TYPE=%s, OrigType=%s, NEST=%d\n"
				, temp->name, temp->real_type, temp->nest_level );
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

	while ( head->next != NULL ) {
		head = head->next;
		temp->next = (type_t *) malloc ( sizeof(type_t) );
		temp = temp->next;
		strcpy(temp->name, head->name);
		strcpy(temp->real_type, type);
		temp->nest_level = nest_level;
	} 
}

void pop_types ( int nest_level )
{
	type_t *type_pointer = type_ll;
	type_t *next_type_pointer;
	// traverse list from beginning
	while( type_pointer->next != NULL )
	{
		// find the point where we enter the current nesting level
		if( type_pointer->next->nest_level < nest_level )
		{
			type_pointer = type_pointer->next;
		}
		else
		{
			// next node is at the requested nesting level, so remove everything from this point on
			next_type_pointer = type_pointer->next;
			type_pointer->next = NULL;
			// now we have two detached linked lists. Free the second one
			while( next_type_pointer != NULL )
			{
				type_pointer = next_type_pointer;
				next_type_pointer = type_pointer->next;
				free( type_pointer );
			}
			break;
		}
	}	
}

void init_all(){

	init_types();
	asm_file = fopen ( "out.s", "w" );

}

void inc_nesting()
{
	nesting++;
}

void dec_nesting()
{
	pop_vars( nesting );
	pop_types( nesting );
	nesting--;
}

int get_nesting()
{
	return nesting;
}

#endif //utils.h_
