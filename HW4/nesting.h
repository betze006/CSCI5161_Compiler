#ifndef NESTING_H
#define NESTING_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//======================================================
//------------------   FUNC PROTOTYPES    --------------
//======================================================

void inc_nesting();

void dec_nesting();

int get_nesting();

void inc_linenumber();

void dec_linenumber();

int get_linenumber();

void newlines_in_comment( const char *text );

void print_current_line();

void inc_errors();

void dec_errors();

int get_errors();

#endif //nesting.h_
