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

#endif //semantic_routines.h_
