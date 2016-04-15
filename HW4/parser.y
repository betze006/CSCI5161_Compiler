/* ===== Definition Section ===== */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nesting.h"
#include "symbol_tables.h"
#include "semantic_routines.h"
#include "codegen.h"

type_t int_type;
type_t float_type;
type_t string_type;

%}

%union {
  char* str;
  int ival;
  float fval;
  id_list_t *ID_List;
  param_list_t *Param_List;
  decl_list_t *Decl_List;
  type_t EXPR_type;
}

%token <str> ID
%token <ival> CONST
%token <str> CONSTS
%token <fval> CONSTF
%token <str> VOID    
%token <str> INT     
%token <str> FLOAT   
%token IF      
%token ELSE    
%token WHILE   
%token FOR
%token STRUCT  
%token TYPEDEF 
%token OP_ASSIGN  
%token OP_OR   
%token OP_AND  
%token OP_NOT  
%token OP_EQ   
%token OP_NE   
%token OP_GT   
%token OP_LT   
%token OP_GE   
%token OP_LE   
%token OP_PLUS 
%token OP_MINUS        
%token OP_TIMES        
%token OP_DIVIDE       
%token MK_LB 
%token MK_RB 
%token MK_LPAREN       
%token MK_RPAREN       
%token MK_LBRACE       
%token MK_RBRACE       
%token MK_COMMA        
%token MK_SEMICOLON    
%token MK_DOT  
%token ERROR
%token RETURN

%start program

%type <str> type
%type <ID_List> init_id_list
%type <ID_List> init_id
%type <ID_List> id_list
%type <Param_List> param_list
%type <Param_List> param
%type <ival> dim_decl
%type <ival> dim_fn
%type <ival> dimfn1
%type <str> tag
%type <str> struct_type
%type <str> struct_tail
%type <EXPR_type> relop_expr_list
%type <EXPR_type> nonempty_relop_expr_list
%type <EXPR_type> relop_expr
%type <EXPR_type> relop_term
%type <EXPR_type> relop_factor
%type <EXPR_type> expr
%type <EXPR_type> term
%type <EXPR_type> factor
%type <EXPR_type> function_call
%type <EXPR_type> var_ref
%type <ival> var_ref_dim
%type <ival> mul_op
%type <ival> add_op
%type <ival> rel_op
%type <ival> op_or
%type <ival> op_and

%%

/* ==== Grammar Section ==== */

/* Productions */               /* Semantic actions */
program		: { init_all(); strcpy(int_type.real_type, "int"); strcpy(string_type.real_type, "string"); strcpy(float_type.real_type, "float"); } global_decl_list { print_vars(); print_types(); print_funcs(); print_structs(); print_all_asm(); close_asm_file();}
		;

global_decl_list: global_decl_list global_decl
                |
		;

global_decl	: decl_list function_decl
		| function_decl
		;

function_decl	: type ID MK_LPAREN param_list MK_RPAREN MK_LBRACE {func_decl($1, $2, $4); inc_nesting();} block MK_RBRACE{dec_nesting();}
		/* | Other function_decl productions */
                /*Empty parameter list.*/
		| type ID MK_LPAREN MK_RPAREN MK_LBRACE {func_decl($1, $2, NULL); inc_nesting();} block MK_RBRACE {dec_nesting();}
                /*Function declarations. The above ones are function definitions*/
		| type ID MK_LPAREN param_list MK_RPAREN MK_SEMICOLON {func_decl($1, $2, $4);}
		| type ID MK_LPAREN MK_RPAREN MK_SEMICOLON {func_decl($1, $2, NULL);}
		;

param_list	: param_list MK_COMMA  param { $$->next=$3; }
		| param	
		;

param		: type ID { $$=func_param_decl ( $1, $2, 0, get_nesting()+1 ); }
		| struct_type ID { $$=NULL; }
		| type ID dim_fn { $$=func_param_decl ( $1, $2, $3, get_nesting()+1 ); }
		| struct_type ID dim_fn { $$=NULL; }
		;

dim_fn		:MK_LB expr_null MK_RB dimfn1 {$$=$4+1;}
		;

dimfn1		:MK_LB expr MK_RB dimfn1 {$$=$4+1;}
		| {$$=0;}
		;

expr_null	:expr
		|
		;

block           : decl_list stmt_list
                | stmt_list
                | decl_list
                | 
                ;
 
decl_list	: decl_list decl
		| decl
		;

decl		: type_decl
		| var_decl
		;

type_decl 	: TYPEDEF type id_list MK_SEMICOLON { type_def($2, $3, get_nesting()); }
		| TYPEDEF VOID id_list MK_SEMICOLON  { type_def($2, $3, get_nesting()); }
		| TYPEDEF struct_type id_list MK_SEMICOLON { type_def($2, $3, get_nesting()); }
		| struct_type MK_SEMICOLON 
		;

var_decl	: type init_id_list MK_SEMICOLON { add_var_list($1, $2, get_nesting()); }
		| struct_type id_list MK_SEMICOLON { add_var_list($1, $2, get_nesting()); }
		| ID id_list MK_SEMICOLON { add_var_list($1, $2, get_nesting()); }
		;

/* Suppported types. */
type		: INT {$$=$1;}
		| FLOAT {$$=$1;}
		| VOID {$$=$1;}
        	|error{$$="error";}
		;

struct_type	: STRUCT tag {$$=build_struct_type( $2 );}
		;

/* Struct variable body. */
tag		: ID MK_LBRACE {inc_nesting();} decl_list MK_RBRACE {struct_decl( $1 ); dec_nesting(); $$=$1;}
		| MK_LBRACE {inc_nesting();} decl_list MK_RBRACE {struct_decl( get_random_name() ); dec_nesting(); $$=get_random_name();}
		| ID MK_LBRACE {inc_nesting();} MK_RBRACE {struct_decl( $1 ); dec_nesting(); $$=$1;}
		| MK_LBRACE {inc_nesting();} MK_RBRACE {struct_decl( get_random_name() ); dec_nesting(); $$=get_random_name();}
		| ID {$$=$1;}
        ;


id_list		: ID { $$=var_decl($1, 0); }
		| id_list MK_COMMA ID { $$=var_decl($3, 0); $$->next=$1; }
		| id_list MK_COMMA ID dim_decl { $$=var_decl($3, $4); $$->next=$1; }
		| ID dim_decl { $$=var_decl($1, $2); }
		;
dim_decl	: MK_LB cexpr MK_RB {$$=1;}
		| dim_decl MK_LB cexpr MK_RB {$$=$1+1;}
		;
cexpr		: cexpr add_op mcexpr
		| mcexpr
		;  
mcexpr		: mcexpr mul_op cfactor
		| cfactor 
		;

cfactor:	CONST 
		|	CONSTF
		| MK_LPAREN cexpr MK_RPAREN
		;

init_id_list	: init_id {$$=$1;}
		| init_id_list MK_COMMA init_id { $3->next=$1 ; $$=$3; }
		;

init_id		: ID { $$=var_decl($1, 0); }
		| ID dim_decl { $$=var_decl($1, $2); }
		| ID OP_ASSIGN relop_expr { $$=var_decl($1, 0); emit_var_assign($1); }
		;

stmt_list	: stmt_list stmt
		| stmt
		;

stmt		: MK_LBRACE{inc_nesting();} block MK_RBRACE{dec_nesting();}
		/* | While Statement here */
		| WHILE MK_LPAREN relop_expr_list MK_RPAREN stmt
	        | FOR MK_LPAREN assign_expr_list MK_SEMICOLON relop_expr_list MK_SEMICOLON assign_expr_list MK_RPAREN stmt 
		/* | If then else here */ 
		| IF MK_LPAREN relop_expr MK_RPAREN stmt ELSE stmt
		/* | If statement here */ 
		| IF MK_LPAREN relop_expr MK_RPAREN stmt 
		/* | read and write library calls -- note that read/write are not keywords */ 
		| function_call
		| var_ref OP_ASSIGN relop_expr MK_SEMICOLON { check_array_dimmension( $1 ); check_assign_types($1, $3); emit_var_assign($1.name);}
		| relop_expr_list MK_SEMICOLON
		| MK_SEMICOLON
		| RETURN MK_SEMICOLON { type_t temp; strcpy(temp.real_type, "void"); check_func_return (temp); emit_return(); }
		| RETURN relop_expr MK_SEMICOLON { check_func_return($2); emit_return();}
		;

function_call    : ID MK_LPAREN relop_expr_list MK_RPAREN { $$ = check_func_call( $1, $3.param_count ); emit_func_call($1, $3.param_count, $3.real_type); }
                 ;

assign_expr_list : nonempty_assign_expr_list
                |
                ;

nonempty_assign_expr_list        : nonempty_assign_expr_list MK_COMMA assign_expr
                | assign_expr

assign_expr     : ID {process_id($1);} OP_ASSIGN relop_expr {emit_var_assign($1);}
                | relop_expr


relop_expr	: relop_term { $$=$1; }
		| relop_expr op_or relop_term  { $$=$1 ; check_op_types ( $1, $3 ); emit_op($2);  }
		;

op_or : OP_OR { emit_move_to_live(); $$=4; }
		;

relop_term	: relop_factor { $$=$1; }
		| relop_term op_and relop_factor { $$=$1 ; check_op_types ( $1, $3 );  emit_op($2); }
		;

op_and : OP_AND { emit_move_to_live(); $$=5; }
		;

relop_factor	: expr { $$=$1; }
		| expr rel_op expr { $$=$1 ; check_op_types ( $1, $3 ); emit_op($2);}
		;

/* Relational operators added.*/
rel_op		: OP_LT { emit_move_to_live(); $$=6; }
		| OP_LE { emit_move_to_live(); $$=7; }
		| OP_GT { emit_move_to_live(); $$=8; }
		| OP_GE { emit_move_to_live(); $$=9; }
		| OP_EQ { emit_move_to_live(); $$=10; }
		| OP_NE { emit_move_to_live(); $$=11; }
		;

relop_expr_list	: nonempty_relop_expr_list { $$=$1 ;  $$.param_count=$1.param_count; }
		| { $$.param_count=0; }
		;

nonempty_relop_expr_list	: nonempty_relop_expr_list MK_COMMA relop_expr { $$=$1 ; $$.param_count = $1.param_count + 1; emit_move_to_live(); }
		| relop_expr { $$=$1 ; $$.param_count = 1; emit_move_to_live(); }
		;

expr		: expr add_op term { $$=$1 ; check_op_types ( $1, $3 ); emit_op($2); }
		| term { $$=$1; }
		;

add_op		: OP_PLUS { emit_move_to_live(); $$=2; }
		| OP_MINUS { emit_move_to_live(); $$=3; }
		;

term		: term mul_op  factor { $$=$1 ; check_op_types ( $1, $3 ); emit_op($2); }
		| factor  { $$=$1; }
		;

mul_op		: OP_TIMES { emit_move_to_live(); $$=0; }
		| OP_DIVIDE { emit_move_to_live();  $$=1; }
		;

factor		: MK_LPAREN relop_expr MK_RPAREN { $$ = $2; }
		/* | -(<relop_expr>) */ 
		| OP_NOT MK_LPAREN relop_expr MK_RPAREN { $$ = $3; emit_not();}
                /* OP_MINUS condition added as C could have a condition like: "if(-(i < 10))".	*/		
		| OP_MINUS MK_LPAREN relop_expr MK_RPAREN { $$ = $3; emit_negate();}
		| CONST	{ $$ = int_type; emit_const_loadi($1); }
		| CONSTF { emit_const_loadf($1); printf("floating point %f\n", $1); $$ = float_type; }
		/* | - constant, here - is an Unary operator */ 
		| OP_NOT CONST 	{ $$ = int_type; emit_const_loadi($2); emit_not(); }
		| OP_NOT CONSTF 	{ $$ = float_type; emit_const_loadf($2); emit_not(); }
                /*OP_MINUS condition added as C could have a condition like: "if(-10)".	*/		
		| OP_MINUS CONST 	{ $$ = int_type; emit_const_loadi($2); emit_negate(); }
		| OP_MINUS CONSTF 	{ $$ = float_type; emit_const_loadf($2); emit_negate(); }
		| function_call { $$=$1; }
		/* | - func ( <relop_expr_list> ) */ 
		| OP_NOT ID MK_LPAREN relop_expr_list MK_RPAREN { $$ = check_func_call( $2, $4.param_count ); emit_not(); }
                /* OP_MINUS condition added as C could have a condition like: "if(-read(i))".	*/	
		| OP_MINUS ID MK_LPAREN relop_expr_list MK_RPAREN { $$ = check_func_call( $2, $4.param_count ); emit_negate(); }
		| var_ref { $$=$1; check_array_dimmension($1); }
		/* | - var-reference */ 
		| OP_NOT var_ref { $$=$2; check_array_dimmension($2); emit_not();}
                /* OP_MINUS condition added as C could have a condition like: "if(-a)".	*/	
		| OP_MINUS var_ref { $$=$2; check_array_dimmension($2); emit_negate();}
		| CONSTS { emit_load_string($1); $$=string_type;}
		;

var_ref		: ID {process_id($1); $$=check_id_type($1); $$.param_count=0; $$.dim_count_struct=-1; emit_load_var($1); }
		| var_ref var_ref_dim { $1.param_count=$2; $$=$1; }
		| var_ref struct_tail { check_array_dimmension($1); $$=struct_ref($1.name, $2); $$.dim_count_struct = array_dimmension_struct($$, $1.name); $$.param_count=0; }
		;

var_ref_dim	: dim { $$=1; }
		|	dim var_ref_dim { $$=$2+1; }
		;

dim		: MK_LB expr MK_RB { check_dim_type($2); }
		;

struct_tail	: MK_DOT ID {$$=$2;}
		;
%%
#include "lex.yy.c"

int scope = 0;

int main (int argc, char *argv[])
{
	int errors_found = 0;
    //init_symtab();
    if(argc>0)
        yyin = fopen(argv[1],"r");
    else
        yyin=stdin;
    yyparse();
	if( (errors_found=get_errors())==0 )
	{
    	printf("%s\n", "Parsing completed. No errors found.");
	}
	else
	{
		printf("Parsing completed. %d errors found.\n", errors_found);
	}
    //cleanup_symtab();
    return 0;
} /* main */


yyerror (mesg)
char *mesg;
  {
      printf("%s\t%d\t%s\t%s\n", "Error found in Line ", get_linenumber(), "next token: ", yytext );
      printf("%s\n", mesg);
      exit(1);
  }
