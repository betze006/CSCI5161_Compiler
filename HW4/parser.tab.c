/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 3 "parser.y"

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


/* Line 371 of yacc.c  */
#line 83 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CONST = 259,
     CONSTS = 260,
     CONSTF = 261,
     VOID = 262,
     INT = 263,
     FLOAT = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     STRUCT = 269,
     TYPEDEF = 270,
     OP_ASSIGN = 271,
     OP_OR = 272,
     OP_AND = 273,
     OP_NOT = 274,
     OP_EQ = 275,
     OP_NE = 276,
     OP_GT = 277,
     OP_LT = 278,
     OP_GE = 279,
     OP_LE = 280,
     OP_PLUS = 281,
     OP_MINUS = 282,
     OP_TIMES = 283,
     OP_DIVIDE = 284,
     MK_LB = 285,
     MK_RB = 286,
     MK_LPAREN = 287,
     MK_RPAREN = 288,
     MK_LBRACE = 289,
     MK_RBRACE = 290,
     MK_COMMA = 291,
     MK_SEMICOLON = 292,
     MK_DOT = 293,
     ERROR = 294,
     RETURN = 295
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 18 "parser.y"

  char* str;
  int ival;
  float fval;
  id_list_t *ID_List;
  param_list_t *Param_List;
  decl_list_t *Decl_List;
  type_t EXPR_type;


/* Line 387 of yacc.c  */
#line 174 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 202 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNRULES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    14,    16,    17,
      27,    28,    37,    44,    50,    54,    56,    59,    62,    66,
      70,    75,    80,    81,    83,    84,    87,    89,    91,    92,
      95,    97,    99,   101,   106,   111,   116,   119,   123,   127,
     131,   133,   135,   137,   139,   142,   143,   149,   150,   155,
     156,   161,   162,   166,   168,   170,   174,   179,   182,   186,
     191,   195,   197,   201,   203,   205,   207,   211,   213,   217,
     219,   222,   226,   229,   231,   232,   237,   238,   239,   247,
     248,   249,   250,   263,   264,   270,   273,   275,   280,   283,
     285,   288,   292,   293,   299,   304,   306,   307,   311,   313,
     314,   319,   321,   323,   327,   329,   331,   335,   337,   339,
     343,   345,   347,   349,   351,   353,   355,   357,   358,   362,
     364,   368,   370,   372,   374,   378,   380,   382,   384,   388,
     393,   398,   400,   402,   405,   408,   411,   414,   416,   422,
     428,   430,   433,   436,   438,   440,   443,   446,   448,   451,
     455
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    43,    44,    -1,    44,    45,    -1,
      -1,    55,    46,    -1,    46,    -1,    -1,    59,     3,    32,
      49,    33,    34,    47,    54,    35,    -1,    -1,    59,     3,
      32,    33,    34,    48,    54,    35,    -1,    59,     3,    32,
      49,    33,    37,    -1,    59,     3,    32,    33,    37,    -1,
      49,    36,    50,    -1,    50,    -1,    59,     3,    -1,    60,
       3,    -1,    59,     3,    51,    -1,    60,     3,    51,    -1,
      30,    53,    31,    52,    -1,    30,    97,    31,    52,    -1,
      -1,    97,    -1,    -1,    55,    73,    -1,    73,    -1,    55,
      -1,    -1,    55,    56,    -1,    56,    -1,    57,    -1,    58,
      -1,    15,    59,    66,    37,    -1,    15,     7,    66,    37,
      -1,    15,    60,    66,    37,    -1,    60,    37,    -1,    59,
      71,    37,    -1,    60,    66,    37,    -1,     3,    66,    37,
      -1,     8,    -1,     9,    -1,     7,    -1,     1,    -1,    14,
      61,    -1,    -1,     3,    34,    62,    55,    35,    -1,    -1,
      34,    63,    55,    35,    -1,    -1,     3,    34,    64,    35,
      -1,    -1,    34,    65,    35,    -1,     3,    -1,     3,    -1,
      66,    36,     3,    -1,    66,    36,     3,    67,    -1,     3,
      67,    -1,    30,    68,    31,    -1,    67,    30,    68,    31,
      -1,    68,    98,    69,    -1,    69,    -1,    69,   100,    70,
      -1,    70,    -1,     4,    -1,     6,    -1,    32,    68,    33,
      -1,    72,    -1,    71,    36,    72,    -1,     3,    -1,     3,
      67,    -1,     3,    16,    89,    -1,    73,    74,    -1,    74,
      -1,    -1,    34,    75,    54,    35,    -1,    -1,    -1,    12,
      76,    32,    95,    77,    33,    74,    -1,    -1,    -1,    -1,
      13,    32,    85,    37,    78,    95,    37,    79,    85,    33,
      80,    74,    -1,    -1,    82,    74,    11,    81,    74,    -1,
      82,    74,    -1,    84,    -1,   102,    16,    89,    37,    -1,
      95,    37,    -1,    37,    -1,    40,    37,    -1,    40,    89,
      37,    -1,    -1,    10,    83,    32,    89,    33,    -1,     3,
      32,    95,    33,    -1,    86,    -1,    -1,    86,    36,    87,
      -1,    87,    -1,    -1,     3,    88,    16,    89,    -1,    89,
      -1,    91,    -1,    89,    90,    91,    -1,    17,    -1,    93,
      -1,    91,    92,    93,    -1,    18,    -1,    97,    -1,    97,
      94,    97,    -1,    23,    -1,    25,    -1,    22,    -1,    24,
      -1,    20,    -1,    21,    -1,    96,    -1,    -1,    96,    36,
      89,    -1,    89,    -1,    97,    98,    99,    -1,    99,    -1,
      26,    -1,    27,    -1,    99,   100,   101,    -1,   101,    -1,
      28,    -1,    29,    -1,    32,    89,    33,    -1,    19,    32,
      89,    33,    -1,    27,    32,    89,    33,    -1,     4,    -1,
       6,    -1,    19,     4,    -1,    19,     6,    -1,    27,     4,
      -1,    27,     6,    -1,    84,    -1,    19,     3,    32,    95,
      33,    -1,    27,     3,    32,    95,    33,    -1,   102,    -1,
      19,   102,    -1,    27,   102,    -1,     5,    -1,     3,    -1,
     102,   103,    -1,   102,   105,    -1,   104,    -1,   104,   103,
      -1,    30,    97,    31,    -1,    38,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   106,   109,   110,   113,   114,   117,   117,
     120,   120,   122,   123,   126,   127,   130,   131,   132,   133,
     136,   139,   140,   143,   144,   147,   148,   149,   150,   153,
     154,   157,   158,   161,   162,   163,   164,   167,   168,   169,
     173,   174,   175,   176,   179,   183,   183,   184,   184,   185,
     185,   186,   186,   187,   191,   192,   193,   194,   196,   197,
     199,   200,   202,   203,   206,   207,   208,   211,   212,   215,
     216,   217,   220,   221,   224,   224,   226,   226,   226,   227,
     227,   227,   227,   229,   229,   231,   233,   234,   235,   236,
     237,   238,   241,   241,   244,   247,   248,   251,   252,   254,
     254,   255,   258,   259,   262,   265,   266,   269,   272,   273,
     277,   278,   279,   280,   281,   282,   285,   286,   289,   290,
     293,   294,   297,   298,   301,   302,   305,   306,   309,   311,
     313,   314,   315,   317,   318,   320,   321,   322,   324,   326,
     327,   329,   331,   332,   335,   336,   337,   340,   341,   344,
     347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONST", "CONSTS", "CONSTF",
  "VOID", "INT", "FLOAT", "IF", "ELSE", "WHILE", "FOR", "STRUCT",
  "TYPEDEF", "OP_ASSIGN", "OP_OR", "OP_AND", "OP_NOT", "OP_EQ", "OP_NE",
  "OP_GT", "OP_LT", "OP_GE", "OP_LE", "OP_PLUS", "OP_MINUS", "OP_TIMES",
  "OP_DIVIDE", "MK_LB", "MK_RB", "MK_LPAREN", "MK_RPAREN", "MK_LBRACE",
  "MK_RBRACE", "MK_COMMA", "MK_SEMICOLON", "MK_DOT", "ERROR", "RETURN",
  "$accept", "program", "$@1", "global_decl_list", "global_decl",
  "function_decl", "$@2", "$@3", "param_list", "param", "dim_fn", "dimfn1",
  "expr_null", "block", "decl_list", "decl", "type_decl", "var_decl",
  "type", "struct_type", "tag", "$@4", "$@5", "$@6", "$@7", "id_list",
  "dim_decl", "cexpr", "mcexpr", "cfactor", "init_id_list", "init_id",
  "stmt_list", "stmt", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "if_stmt", "$@15", "function_call", "assign_expr_list",
  "nonempty_assign_expr_list", "assign_expr", "$@16", "relop_expr",
  "op_or", "relop_term", "op_and", "relop_factor", "rel_op",
  "relop_expr_list", "nonempty_relop_expr_list", "expr", "add_op", "term",
  "mul_op", "factor", "var_ref", "var_ref_dim", "dim", "struct_tail", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    45,    45,    47,    46,
      48,    46,    46,    46,    49,    49,    50,    50,    50,    50,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    56,    56,    57,    57,    57,    57,    58,    58,    58,
      59,    59,    59,    59,    60,    62,    61,    63,    61,    64,
      61,    65,    61,    61,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    72,    73,    73,    75,    74,    76,    77,    74,    78,
      79,    80,    74,    81,    74,    74,    74,    74,    74,    74,
      74,    74,    83,    82,    84,    85,    85,    86,    86,    88,
      87,    87,    89,    89,    90,    91,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   102,   103,   103,   104,
     105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     0,     9,
       0,     8,     6,     5,     3,     1,     2,     2,     3,     3,
       4,     4,     0,     1,     0,     2,     1,     1,     0,     2,
       1,     1,     1,     4,     4,     4,     2,     3,     3,     3,
       1,     1,     1,     1,     2,     0,     5,     0,     4,     0,
       4,     0,     3,     1,     1,     3,     4,     2,     3,     4,
       3,     1,     3,     1,     1,     1,     3,     1,     3,     1,
       2,     3,     2,     1,     0,     4,     0,     0,     7,     0,
       0,     0,    12,     0,     5,     2,     1,     4,     2,     1,
       2,     3,     0,     5,     4,     1,     0,     3,     1,     0,
       4,     1,     1,     3,     1,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     4,
       4,     1,     1,     2,     2,     2,     2,     1,     5,     5,
       1,     2,     2,     1,     1,     2,     2,     1,     2,     3,
       2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     5,     1,     0,    43,     0,    42,    40,    41,
       0,     0,     4,     7,     0,    30,    31,    32,     0,     0,
      54,     0,    53,    47,    44,     0,     0,     0,     6,    29,
      69,     0,    67,    36,     0,     0,    57,     0,    39,    45,
       0,     0,     0,     0,     0,     0,     0,    70,     0,    37,
      38,    64,    65,     0,     0,    61,    63,     0,    55,     0,
       0,     0,     0,    52,    34,    33,    35,   144,   131,   143,
     132,     0,     0,     0,   137,    71,   102,   105,   108,   121,
     125,   140,     0,     0,    15,     0,     0,    69,    68,     0,
     122,   123,    58,     0,   126,   127,     0,     0,    56,     0,
      50,    48,   117,   144,   133,   134,     0,   141,   144,   135,
     136,     0,   142,     0,   104,     0,   107,     0,   114,   115,
     112,   110,   113,   111,     0,     0,     0,     0,     0,   145,
     147,   146,    10,    13,     0,     0,    16,    17,    66,    60,
      62,    59,    46,   119,     0,   116,   117,     0,   117,     0,
     128,   103,   106,   109,   120,   124,     0,   150,   148,     0,
       8,    12,    14,    24,    18,    19,    94,     0,     0,   129,
       0,   130,   149,   144,    92,    76,     0,    74,    89,     0,
       0,     0,    26,    73,     0,    86,     0,   140,     0,     0,
      23,   118,   138,   139,     0,     0,    96,     0,    90,     0,
      11,    25,    72,    85,    88,     0,     0,    22,     0,   117,
     144,     0,    95,    98,   101,     0,    91,    83,     0,     9,
       0,    20,     0,    77,     0,    79,     0,    75,     0,    87,
       0,    93,     0,     0,   117,    97,    84,    22,     0,   100,
       0,    21,    78,    80,    96,     0,    81,     0,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    12,    13,   188,   159,    83,    84,
     164,   221,   189,   180,   181,    15,    16,    17,    62,    19,
      24,    59,    40,    60,    41,    21,    47,    54,    55,    56,
      31,    32,   182,   183,   197,   195,   232,   234,   244,   247,
     228,   184,   194,    74,   211,   212,   213,   224,   143,   115,
      76,   117,    77,   124,   186,   145,    78,   125,    79,    96,
      80,    81,   129,   130,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -172
static const yytype_int16 yypact[] =
{
    -172,    32,  -172,  -172,   321,  -172,    24,  -172,  -172,  -172,
      13,   158,  -172,  -172,   129,  -172,  -172,  -172,    64,    21,
      42,   120,    43,    71,  -172,    24,    24,    24,  -172,  -172,
      87,   169,  -172,  -172,   231,    17,    66,   106,  -172,    78,
     129,   104,   240,   242,   249,   268,    62,    66,   123,  -172,
    -172,  -172,  -172,    17,   182,   190,  -172,    17,    42,   129,
     127,    72,   123,  -172,  -172,  -172,  -172,   132,  -172,  -172,
    -172,    27,   117,   268,  -172,   154,   155,  -172,   317,   190,
    -172,   103,   116,   147,  -172,   172,   211,   112,  -172,   217,
    -172,  -172,  -172,    17,  -172,  -172,    17,   225,    66,    90,
    -172,  -172,   268,   184,  -172,  -172,   268,   103,   189,  -172,
    -172,   268,   103,    51,  -172,   268,  -172,   268,  -172,  -172,
    -172,  -172,  -172,  -172,   268,   268,   268,   268,   221,  -172,
     196,  -172,  -172,  -172,   153,   203,   207,   207,  -172,   190,
    -172,  -172,  -172,   154,   209,   254,   268,    61,   268,    83,
    -172,   155,  -172,   262,   190,  -172,   228,  -172,  -172,   188,
    -172,  -172,  -172,   268,  -172,  -172,  -172,   268,   224,  -172,
     258,  -172,  -172,     9,  -172,  -172,   260,  -172,  -172,   243,
     259,   226,   142,  -172,   142,   291,   256,    18,   188,   265,
     262,   154,  -172,  -172,   266,   267,   278,   188,  -172,     2,
    -172,   142,  -172,   290,  -172,   268,   269,   272,   268,   268,
      28,   270,   282,  -172,   154,   271,  -172,  -172,    73,  -172,
     268,  -172,    91,  -172,   287,  -172,   278,  -172,   142,  -172,
     238,  -172,   292,   268,   268,  -172,  -172,   272,   142,   154,
     286,  -172,  -172,  -172,   278,   293,  -172,   142,  -172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,  -172,  -172,   318,  -172,  -172,  -172,   198,
     194,    97,  -172,  -171,     3,   -11,  -172,  -172,     0,    -6,
    -172,  -172,  -172,  -172,  -172,   159,    -5,   -28,   252,   250,
    -172,   299,   167,  -164,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -146,   105,  -172,   124,  -172,   -45,  -172,
     236,  -172,   235,  -172,   -94,  -172,  -118,   -32,   229,   -69,
     227,   -70,   230,  -172,  -172
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -138
static const yytype_int16 yytable[] =
{
      75,   107,   112,    29,    18,    27,   153,    14,   144,   156,
     126,    26,    20,   185,    18,    36,    22,   206,   202,   114,
     203,    51,    93,    52,    20,    89,   215,    20,   113,    97,
     103,   104,     3,   105,   205,   185,   185,   202,   185,   216,
      86,   102,   185,    61,   -99,   190,    85,    23,   127,    53,
      29,   185,   168,    98,   170,   185,   128,    93,    33,   106,
     102,   147,    99,     5,   236,    93,   149,    30,   114,     7,
       8,     9,    35,     5,   242,     6,    10,    39,   114,     7,
       8,     9,   185,   248,   150,   126,    10,    11,    29,   187,
     114,     5,   185,     6,   169,    82,    57,     7,     8,     9,
     114,   185,   230,    45,    10,    11,   -51,   101,   114,    58,
     229,   187,   187,   -49,   187,   223,   171,    35,   187,    46,
     108,   109,   191,   110,   231,   142,    87,   187,    45,    86,
       5,   187,     6,   127,   199,    85,     7,     8,     9,    63,
     240,   128,    35,    10,    11,    67,    68,    69,    70,   111,
     132,   214,   174,   133,   175,   176,    37,    38,   187,     5,
     218,    71,   100,   222,   102,    25,     8,     9,   187,    72,
      29,   114,    10,   116,    73,   136,   177,   187,    34,   178,
     134,   214,   179,   135,    42,    43,    44,   160,   239,     5,
     161,   173,    68,    69,    70,     7,     8,     9,   174,   214,
     175,   176,    10,    11,     5,    48,    49,    71,    90,    91,
       7,     8,     9,    92,   137,    72,   146,    10,    94,    95,
      73,   148,   177,   -28,   157,   178,   127,     5,   179,   173,
      68,    69,    70,     7,     8,     9,   174,   163,   175,   176,
      10,    11,   166,    90,    91,    71,    67,    68,    69,    70,
     138,    90,    91,    72,    90,    91,   141,   192,    73,   172,
     177,   -27,    71,   178,    90,    91,   179,    37,    50,   237,
      72,    67,    68,    69,    70,    73,    37,    64,    37,    65,
     198,   210,    68,    69,    70,    37,    66,    71,    90,    91,
     167,   193,   196,   204,   200,    72,   207,    71,   208,   209,
      73,   217,   220,   233,   219,    72,   227,   225,  -137,  -137,
      73,  -137,  -137,  -137,  -137,  -137,  -137,  -137,   226,  -137,
    -137,    -3,     5,   243,     6,   238,   246,  -137,     7,     8,
       9,   165,    28,   162,   241,    10,    11,   118,   119,   120,
     121,   122,   123,    90,    91,   139,   140,    88,   201,   245,
     235,   151,   152,   155,   154,     0,     0,     0,     0,     0,
     158
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      45,    71,    72,    14,     4,    11,   124,     4,   102,   127,
      79,    11,     3,   159,    14,    20,     3,   188,   182,    17,
     184,     4,    54,     6,     3,    53,   197,     3,    73,    57,
       3,     4,     0,     6,    16,   181,   182,   201,   184,    37,
      46,    32,   188,    40,    16,   163,    46,    34,    30,    32,
      61,   197,   146,    58,   148,   201,    38,    89,    37,    32,
      32,   106,    59,     1,   228,    97,   111,     3,    17,     7,
       8,     9,    30,     1,   238,     3,    14,    34,    17,     7,
       8,     9,   228,   247,    33,   154,    14,    15,    99,   159,
      17,     1,   238,     3,    33,    33,    30,     7,     8,     9,
      17,   247,   220,    16,    14,    15,    35,    35,    17,     3,
      37,   181,   182,    35,   184,   209,    33,    30,   188,    32,
       3,     4,   167,     6,    33,    35,     3,   197,    16,   135,
       1,   201,     3,    30,   179,   135,     7,     8,     9,    35,
     234,    38,    30,    14,    15,     3,     4,     5,     6,    32,
      34,   196,    10,    37,    12,    13,    36,    37,   228,     1,
     205,    19,    35,   208,    32,     7,     8,     9,   238,    27,
     181,    17,    14,    18,    32,     3,    34,   247,    19,    37,
      33,   226,    40,    36,    25,    26,    27,    34,   233,     1,
      37,     3,     4,     5,     6,     7,     8,     9,    10,   244,
      12,    13,    14,    15,     1,    36,    37,    19,    26,    27,
       7,     8,     9,    31,     3,    27,    32,    14,    28,    29,
      32,    32,    34,    35,     3,    37,    30,     1,    40,     3,
       4,     5,     6,     7,     8,     9,    10,    30,    12,    13,
      14,    15,    33,    26,    27,    19,     3,     4,     5,     6,
      33,    26,    27,    27,    26,    27,    31,    33,    32,    31,
      34,    35,    19,    37,    26,    27,    40,    36,    37,    31,
      27,     3,     4,     5,     6,    32,    36,    37,    36,    37,
      37,     3,     4,     5,     6,    36,    37,    19,    26,    27,
      36,    33,    32,    37,    35,    27,    31,    19,    32,    32,
      32,    11,    30,    16,    35,    27,    35,    37,    17,    18,
      32,    20,    21,    22,    23,    24,    25,    26,    36,    28,
      29,     0,     1,    37,     3,    33,    33,    36,     7,     8,
       9,   137,    14,   135,   237,    14,    15,    20,    21,    22,
      23,    24,    25,    26,    27,    93,    96,    48,   181,   244,
     226,   115,   117,   126,   125,    -1,    -1,    -1,    -1,    -1,
     130
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,     0,    44,     1,     3,     7,     8,     9,
      14,    15,    45,    46,    55,    56,    57,    58,    59,    60,
       3,    66,     3,    34,    61,     7,    59,    60,    46,    56,
       3,    71,    72,    37,    66,    30,    67,    36,    37,    34,
      63,    65,    66,    66,    66,    16,    32,    67,    36,    37,
      37,     4,     6,    32,    68,    69,    70,    30,     3,    62,
      64,    55,    59,    35,    37,    37,    37,     3,     4,     5,
       6,    19,    27,    32,    84,    89,    91,    93,    97,    99,
     101,   102,    33,    49,    50,    59,    60,     3,    72,    68,
      26,    27,    31,    98,    28,    29,   100,    68,    67,    55,
      35,    35,    32,     3,     4,     6,    32,   102,     3,     4,
       6,    32,   102,    89,    17,    90,    18,    92,    20,    21,
      22,    23,    24,    25,    94,    98,   100,    30,    38,   103,
     104,   105,    34,    37,    33,    36,     3,     3,    33,    69,
      70,    31,    35,    89,    95,    96,    32,    89,    32,    89,
      33,    91,    93,    97,    99,   101,    97,     3,   103,    48,
      34,    37,    50,    30,    51,    51,    33,    36,    95,    33,
      95,    33,    31,     3,    10,    12,    13,    34,    37,    40,
      54,    55,    73,    74,    82,    84,    95,   102,    47,    53,
      97,    89,    33,    33,    83,    76,    32,    75,    37,    89,
      35,    73,    74,    74,    37,    16,    54,    31,    32,    32,
       3,    85,    86,    87,    89,    54,    37,    11,    89,    35,
      30,    52,    89,    95,    88,    37,    36,    35,    81,    37,
      97,    33,    77,    16,    78,    87,    74,    31,    33,    89,
      95,    52,    74,    37,    79,    85,    33,    80,    74
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { init_all(); strcpy(int_type.real_type, "int"); strcpy(string_type.real_type, "string"); strcpy(float_type.real_type, "float"); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 106 "parser.y"
    { print_vars(); print_types(); print_funcs(); print_structs(); print_all_asm(); close_asm_file();}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 117 "parser.y"
    {func_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].Param_List)); inc_nesting();}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 117 "parser.y"
    {dec_nesting();}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    {func_decl((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), NULL); inc_nesting();}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    {dec_nesting();}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 122 "parser.y"
    {func_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].Param_List));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 123 "parser.y"
    {func_decl((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), NULL);}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 126 "parser.y"
    { (yyval.Param_List)->next=(yyvsp[(3) - (3)].Param_List); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 130 "parser.y"
    { (yyval.Param_List)=func_param_decl ( (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str), 0, get_nesting()+1 ); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 131 "parser.y"
    { (yyval.Param_List)=NULL; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 132 "parser.y"
    { (yyval.Param_List)=func_param_decl ( (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].ival), get_nesting()+1 ); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 133 "parser.y"
    { (yyval.Param_List)=NULL; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 136 "parser.y"
    {(yyval.ival)=(yyvsp[(4) - (4)].ival)+1;}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 139 "parser.y"
    {(yyval.ival)=(yyvsp[(4) - (4)].ival)+1;}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 140 "parser.y"
    {(yyval.ival)=0;}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 153 "parser.y"
    { emit_source_text( ); }
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 161 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 162 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 163 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 167 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 168 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 169 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 173 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 174 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 175 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    {(yyval.str)="error";}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 179 "parser.y"
    {(yyval.str)=build_struct_type( (yyvsp[(2) - (2)].str) );}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    {inc_nesting();}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    {struct_decl( (yyvsp[(1) - (5)].str) ); dec_nesting(); (yyval.str)=(yyvsp[(1) - (5)].str);}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    {inc_nesting();}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    {struct_decl( get_random_name() ); dec_nesting(); (yyval.str)=get_random_name();}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 185 "parser.y"
    {inc_nesting();}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 185 "parser.y"
    {struct_decl( (yyvsp[(1) - (4)].str) ); dec_nesting(); (yyval.str)=(yyvsp[(1) - (4)].str);}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    {inc_nesting();}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 186 "parser.y"
    {struct_decl( get_random_name() ); dec_nesting(); (yyval.str)=get_random_name();}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 187 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (1)].str), 0); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 192 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(3) - (3)].str), 0); (yyval.ID_List)->next=(yyvsp[(1) - (3)].ID_List); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 193 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].ival)); (yyval.ID_List)->next=(yyvsp[(1) - (4)].ID_List); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 194 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 196 "parser.y"
    {(yyval.ival)=1; set_array_dim(0, (int)(yyvsp[(2) - (3)].fval));}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 197 "parser.y"
    {(yyval.ival)=(yyvsp[(1) - (4)].ival)+1; set_array_dim((yyvsp[(1) - (4)].ival), (int)(yyvsp[(3) - (4)].fval)); }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 199 "parser.y"
    { (yyval.fval) = ((yyvsp[(2) - (3)].ival)==2) ? (yyvsp[(1) - (3)].fval)+(yyvsp[(3) - (3)].fval) : (yyvsp[(1) - (3)].fval)-(yyvsp[(3) - (3)].fval) ; }
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 200 "parser.y"
    { (yyval.fval)=(yyvsp[(1) - (1)].fval); }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 202 "parser.y"
    { (yyval.fval) = ((yyvsp[(2) - (3)].ival)==0) ? (yyvsp[(1) - (3)].fval)*(yyvsp[(3) - (3)].fval) : (yyvsp[(1) - (3)].fval)/(yyvsp[(3) - (3)].fval) ; }
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 203 "parser.y"
    { (yyval.fval)=(yyvsp[(1) - (1)].fval); }
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 206 "parser.y"
    { (yyval.fval) = (float) (yyvsp[(1) - (1)].ival); }
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 207 "parser.y"
    { (yyval.fval) = (yyvsp[(1) - (1)].fval); }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 208 "parser.y"
    { (yyval.fval) = (yyvsp[(2) - (3)].fval); }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 211 "parser.y"
    {(yyval.ID_List)=(yyvsp[(1) - (1)].ID_List);}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyvsp[(3) - (3)].ID_List)->next=(yyvsp[(1) - (3)].ID_List) ; (yyval.ID_List)=(yyvsp[(3) - (3)].ID_List); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 215 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (1)].str), 0); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 216 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 217 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (3)].str), 0); emit_var_assign( check_id_type((yyvsp[(1) - (3)].str)) ); }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 220 "parser.y"
    { emit_source_text( ); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    {inc_nesting();}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 224 "parser.y"
    {dec_nesting();}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 226 "parser.y"
    {gen_head();}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 226 "parser.y"
    {gen_test_while();}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 226 "parser.y"
    {gen_label_exit_while();}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {gen_head();}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {gen_test_for();}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {gen_label_for();}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 227 "parser.y"
    {gen_label_exit_for();}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 229 "parser.y"
    {gen_label_if_else();}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 229 "parser.y"
    {gen_label_exit_if_else();}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    {gen_label_exit_if();}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 234 "parser.y"
    { check_array_dimmension( (yyvsp[(1) - (4)].EXPR_type) ); check_assign_types((yyvsp[(1) - (4)].EXPR_type), (yyvsp[(3) - (4)].EXPR_type)); emit_var_assign((yyvsp[(1) - (4)].EXPR_type));}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 237 "parser.y"
    { type_t temp; strcpy(temp.real_type, "void"); check_func_return (temp); emit_return(temp); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { check_func_return((yyvsp[(2) - (3)].EXPR_type)); emit_return((yyvsp[(2) - (3)].EXPR_type));}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    {gen_head();}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 241 "parser.y"
    {gen_test_if();}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 244 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].EXPR_type).param_count ); emit_func_call((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].EXPR_type).param_count, (yyvsp[(3) - (4)].EXPR_type).real_type); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 254 "parser.y"
    {process_id((yyvsp[(1) - (1)].str));}
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 254 "parser.y"
    {emit_var_assign( check_id_type((yyvsp[(1) - (4)].str)) );}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 258 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 259 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival));  }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 262 "parser.y"
    { emit_move_to_live(); (yyval.ival)=4; }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 265 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) );  emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 269 "parser.y"
    { emit_move_to_live(); (yyval.ival)=5; }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 272 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 273 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival));}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 277 "parser.y"
    { emit_move_to_live(); (yyval.ival)=6; }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 278 "parser.y"
    { emit_move_to_live(); (yyval.ival)=7; }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    { emit_move_to_live(); (yyval.ival)=8; }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 280 "parser.y"
    { emit_move_to_live(); (yyval.ival)=9; }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 281 "parser.y"
    { emit_move_to_live(); (yyval.ival)=10; }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 282 "parser.y"
    { emit_move_to_live(); (yyval.ival)=11; }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 285 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type) ;  (yyval.EXPR_type).param_count=(yyvsp[(1) - (1)].EXPR_type).param_count; }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 286 "parser.y"
    { (yyval.EXPR_type).param_count=0; }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 289 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; (yyval.EXPR_type).param_count = (yyvsp[(1) - (3)].EXPR_type).param_count + 1; emit_move_to_live(); emit_save_to_stack(); }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 290 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type) ; (yyval.EXPR_type).param_count = 1; emit_move_to_live(); emit_save_to_stack(); }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 293 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 294 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 297 "parser.y"
    { emit_move_to_live(); (yyval.ival)=2; }
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 298 "parser.y"
    { emit_move_to_live(); (yyval.ival)=3; }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 301 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 302 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 305 "parser.y"
    { emit_move_to_live(); (yyval.ival)=0; }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 306 "parser.y"
    { emit_move_to_live();  (yyval.ival)=1; }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 309 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(2) - (3)].EXPR_type); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(3) - (4)].EXPR_type); emit_not();}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 313 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(3) - (4)].EXPR_type); emit_negate();}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 314 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(1) - (1)].ival)); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    { emit_const_loadf((yyvsp[(1) - (1)].fval)); (yyval.EXPR_type) = float_type; }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 317 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(2) - (2)].ival)); emit_not(); }
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 318 "parser.y"
    { (yyval.EXPR_type) = float_type; emit_const_loadf((yyvsp[(2) - (2)].fval)); emit_not(); }
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 320 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(2) - (2)].ival)); emit_negate(); }
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 321 "parser.y"
    { (yyval.EXPR_type) = float_type; emit_const_loadf((yyvsp[(2) - (2)].fval)); emit_negate(); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 322 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 324 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].EXPR_type).param_count ); emit_not(); }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 326 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].EXPR_type).param_count ); emit_negate(); }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 327 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); check_array_dimmension((yyvsp[(1) - (1)].EXPR_type)); }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(2) - (2)].EXPR_type); check_array_dimmension((yyvsp[(2) - (2)].EXPR_type)); emit_not();}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 331 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(2) - (2)].EXPR_type); check_array_dimmension((yyvsp[(2) - (2)].EXPR_type)); emit_negate();}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 332 "parser.y"
    { emit_load_string((yyvsp[(1) - (1)].str)); (yyval.EXPR_type)=string_type;}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 335 "parser.y"
    {process_id((yyvsp[(1) - (1)].str)); (yyval.EXPR_type)=check_id_type((yyvsp[(1) - (1)].str)); (yyval.EXPR_type).param_count=0; (yyval.EXPR_type).dim_count_struct=-1; emit_load_var((yyvsp[(1) - (1)].str)); strcpy((yyval.EXPR_type).name, (yyvsp[(1) - (1)].str)); }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 336 "parser.y"
    { (yyvsp[(1) - (2)].EXPR_type).param_count=(yyvsp[(2) - (2)].ival); (yyval.EXPR_type)=(yyvsp[(1) - (2)].EXPR_type); emit_adjust_dimm((yyvsp[(1) - (2)].EXPR_type).name); }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 337 "parser.y"
    { check_array_dimmension((yyvsp[(1) - (2)].EXPR_type)); (yyval.EXPR_type)=struct_ref((yyvsp[(1) - (2)].EXPR_type).name, (yyvsp[(2) - (2)].str)); (yyval.EXPR_type).dim_count_struct = array_dimmension_struct((yyval.EXPR_type), (yyvsp[(1) - (2)].EXPR_type).name); (yyval.EXPR_type).param_count=0; }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 340 "parser.y"
    { (yyval.ival)=1; }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 341 "parser.y"
    { (yyval.ival)=(yyvsp[(2) - (2)].ival)+1; }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 344 "parser.y"
    { check_dim_type((yyvsp[(2) - (3)].EXPR_type)); emit_move_to_live(); }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 347 "parser.y"
    {(yyval.str)=(yyvsp[(2) - (2)].str);}
    break;


/* Line 1787 of yacc.c  */
#line 2411 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 349 "parser.y"

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
