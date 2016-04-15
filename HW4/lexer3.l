/*lexer file*/

%{
#include <stdio.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"
%}
letter   [A-Za-z]
digit    [0-9]
kwInt    "int"
kwFloat  "float"
kwVoid   "void"
kwIf     "if"
kwElse   "else"
kwWhile  "while"
kwFor	 "for"
kwStruct "struct"
kwUnion  "union"
kwTypedef "typedef"
kwReturn "return"

ID       ({letter})({letter}|{digit}|"_")*
op_assign        "="
op_or   "||"
op_and  "&&"
op_not  "!"
op_eq   "=="
op_ne   "!="
op_lt   "<"
op_gt   ">"
op_le   "<="
op_ge   ">="
op_plus "+"
op_minus "-"
op_times "*"
op_divide "/"
constantf {digit}+(("."){digit}+)
constanti {digit}+
comment	"/*"(([^*])|([*]+[^/*]))*("*")+"/"
s-const \"([^"\n])*\"
ws       [ \t]+
newline  "\n"
mk_lparen "("
mk_rparen ")"
mk_lbrace "{"
mk_rbrace "}"
mk_lsqbrace "["
mk_rsqbrace "]"
mk_comma  ","
mk_semicolon ";"
mk_dot  "."
error    .

%%

{ws}            { /* */ }
{comment}	    { newlines_in_comment( yytext ); }
{kwInt}         { append_source_text( strdup(yytext) ); yylval.str = strdup(yytext); return INT; }
{kwFloat}       { append_source_text( strdup(yytext) ); yylval.str = strdup(yytext); return FLOAT; }
{kwVoid}		{ append_source_text( strdup(yytext) ); yylval.str = strdup(yytext); return VOID; }
{kwIf}          { append_source_text( strdup(yytext) ); return IF; }
{kwElse}        { append_source_text( strdup(yytext) ); return ELSE; }
{kwWhile}       { append_source_text( strdup(yytext) ); return WHILE; }
{kwFor}      	{ append_source_text( strdup(yytext) ); return FOR; }
{kwStruct}		{ append_source_text( strdup(yytext) ); return STRUCT; }
{kwUnion}		{ append_source_text( strdup(yytext) ); return STRUCT; }
{kwTypedef}     { append_source_text( strdup(yytext) ); return TYPEDEF; }
{kwReturn}      { append_source_text( strdup(yytext) ); return RETURN; }
{ID}            { append_source_text( strdup(yytext) ); yylval.str = strdup(yytext); return ID; }
{op_assign}     { append_source_text( strdup(yytext) ); return OP_ASSIGN; }
{op_and}        { append_source_text( strdup(yytext) ); return OP_AND; }
{op_or}         { append_source_text( strdup(yytext) ); return OP_OR; }
{op_not}        { append_source_text( strdup(yytext) ); return OP_NOT; }
{op_eq}         { append_source_text( strdup(yytext) ); return OP_EQ; }
{op_ne}         { append_source_text( strdup(yytext) ); return OP_NE; }
{op_lt}         { append_source_text( strdup(yytext) ); return OP_LT; }
{op_gt}         { append_source_text( strdup(yytext) ); return OP_GT; }
{op_le}         { append_source_text( strdup(yytext) ); return OP_LE; }
{op_ge}         { append_source_text( strdup(yytext) ); return OP_GE; }
{op_plus}       { append_source_text( strdup(yytext) ); return OP_PLUS; }
{op_minus}      { append_source_text( strdup(yytext) ); return OP_MINUS; }
{op_times}      { append_source_text( strdup(yytext) ); return OP_TIMES; }
{op_divide}     { append_source_text( strdup(yytext) ); return OP_DIVIDE; }
{constanti}     { append_source_text( strdup(yytext) ); yylval.ival = atoi(yytext); return CONST;}
{constantf}		{ append_source_text( strdup(yytext) ); yylval.fval = atof(yytext); return CONSTF;}
{s-const}       { append_source_text( strdup(yytext) ); yylval.str = strdup(yytext); return CONSTS;}
{mk_lparen}     { append_source_text( strdup(yytext) ); return MK_LPAREN; }
{mk_rparen}     { append_source_text( strdup(yytext) ); return MK_RPAREN; }
{mk_lbrace}     { append_source_text( strdup(yytext) ); return MK_LBRACE; }
{mk_rbrace}     { append_source_text( strdup(yytext) ); return MK_RBRACE; }
{mk_lsqbrace}   { append_source_text( strdup(yytext) ); return MK_LB; }
{mk_rsqbrace}   { append_source_text( strdup(yytext) ); return MK_RB; }
{mk_comma}      { append_source_text( strdup(yytext) ); return MK_COMMA; }
{mk_semicolon}  { append_source_text( strdup(yytext) ); return MK_SEMICOLON; }
{mk_dot}		{ append_source_text( strdup(yytext) ); return MK_DOT; }
{newline}       { inc_linenumber(); }
{error}         return ERROR;

%%

