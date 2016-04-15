#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"
#include "codegen.h"

static int nesting = 0;
static int linenumber = 1;
static int errors = 0;

//======================================================
//------------------   FUNC DEFS    --------------------
//======================================================

void inc_nesting()
{
	nesting++;
}

void dec_nesting()
{
	//pop_vars( nesting );
	//pop_types( nesting );
	nesting--;
}

int get_nesting()
{
	return nesting;
}

void inc_linenumber()
{
	linenumber++;
}

void dec_linenumber()
{
	linenumber--;
}

int get_linenumber()
{
	return linenumber;
}

void newlines_in_comment( const char *text )
{
	int i;
	for( i=0; i<strlen(text); i++ )
	{
		if( text[i] == '\n' )
		{
			inc_linenumber();
		}
	}
}

void print_current_line()
{
	printf("Error found in line %d:\n", linenumber);
}

void inc_errors()
{
	errors++;
}

void dec_errors()
{
	errors--;
}

int get_errors()
{
	return errors;
}
