#ifndef CODEGEN_H
#define CODEGEN_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//======================================================
//------------------   FUNC PROTOTYPES    --------------
//======================================================

void open_asm_file( );

void init_codegen();

void close_asm_file( );

int get_sp_offset();

void set_sp_offset( int offset );

void emit_source_text( );

void emit_const_loadf ( float fl );

char *str_append ( char *str1, char*str2 );

void emit_return( type_t ret_type );

void reg_float_to_int( int d );

void reg_int_to_float( int d );

void emit_var_assign ( type_t var_type );

void emit_save_to_stack();

void emit_get_from_live();

void emit_move_to_live();


#endif //codegen.h_
