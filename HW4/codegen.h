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

void emit_const_loadf ( float fl );

#endif //codegen.h_
