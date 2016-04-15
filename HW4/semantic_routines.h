#ifndef SEMANTIC_ROUTINES_H
#define SEMANTIC_ROUTINES_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol_tables.h"

//======================================================
//------------------   FUNC PROTOTYPES    --------------
//======================================================

id_list_t *var_decl (char* name, int dim);

void process_id( char *name );

param_list_t *func_param_decl (char* type, char* name, int dim, int nest_level);

void func_decl ( char *type, char *name, param_list_t *params );

param_list_t *struct_param_decl (char* type, char* name, int dim, int nest_level);

void struct_decl ( char *name );

type_t struct_ref ( char *struct_var_name, char *member_name );

type_t check_func_call ( char *name, int param_count );

type_t check_id_type( char *name );

void check_op_types ( type_t a, type_t b);

void check_assign_types ( type_t a, type_t b);

void check_func_return ( type_t ret_type );

void check_array_dimmension ( type_t id );

int array_dimmension_struct ( type_t id , char *var_name );

void check_dim_type ( type_t dim_type );

#endif //semantic_routines.h_
