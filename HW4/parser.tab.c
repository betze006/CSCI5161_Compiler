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
#define YYLAST   356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNRULES -- Number of states.  */
#define YYNSTATES  241

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
     219,   222,   226,   229,   231,   232,   237,   243,   253,   261,
     267,   269,   274,   277,   279,   282,   286,   291,   293,   294,
     298,   300,   301,   306,   308,   310,   314,   316,   318,   322,
     324,   326,   330,   332,   334,   336,   338,   340,   342,   344,
     345,   349,   351,   355,   357,   359,   361,   365,   367,   369,
     371,   375,   380,   385,   387,   389,   392,   395,   398,   401,
     403,   409,   415,   417,   420,   423,   425,   427,   430,   433,
     435,   438,   442
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
      30,    53,    31,    52,    -1,    30,    89,    31,    52,    -1,
      -1,    89,    -1,    -1,    55,    73,    -1,    73,    -1,    55,
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
      -1,    68,    90,    69,    -1,    69,    -1,    69,    92,    70,
      -1,    70,    -1,     4,    -1,     6,    -1,    32,    68,    33,
      -1,    72,    -1,    71,    36,    72,    -1,     3,    -1,     3,
      67,    -1,     3,    16,    81,    -1,    73,    74,    -1,    74,
      -1,    -1,    34,    75,    54,    35,    -1,    12,    32,    87,
      33,    74,    -1,    13,    32,    77,    37,    87,    37,    77,
      33,    74,    -1,    10,    32,    81,    33,    74,    11,    74,
      -1,    10,    32,    81,    33,    74,    -1,    76,    -1,    94,
      16,    81,    37,    -1,    87,    37,    -1,    37,    -1,    40,
      37,    -1,    40,    81,    37,    -1,     3,    32,    87,    33,
      -1,    78,    -1,    -1,    78,    36,    79,    -1,    79,    -1,
      -1,     3,    80,    16,    81,    -1,    81,    -1,    83,    -1,
      81,    82,    83,    -1,    17,    -1,    85,    -1,    83,    84,
      85,    -1,    18,    -1,    89,    -1,    89,    86,    89,    -1,
      23,    -1,    25,    -1,    22,    -1,    24,    -1,    20,    -1,
      21,    -1,    88,    -1,    -1,    88,    36,    81,    -1,    81,
      -1,    89,    90,    91,    -1,    91,    -1,    26,    -1,    27,
      -1,    91,    92,    93,    -1,    93,    -1,    28,    -1,    29,
      -1,    32,    81,    33,    -1,    19,    32,    81,    33,    -1,
      27,    32,    81,    33,    -1,     4,    -1,     6,    -1,    19,
       4,    -1,    19,     6,    -1,    27,     4,    -1,    27,     6,
      -1,    76,    -1,    19,     3,    32,    87,    33,    -1,    27,
       3,    32,    87,    33,    -1,    94,    -1,    19,    94,    -1,
      27,    94,    -1,     5,    -1,     3,    -1,    94,    95,    -1,
      94,    97,    -1,    96,    -1,    96,    95,    -1,    30,    89,
      31,    -1,    38,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   103,   106,   107,   110,   111,   114,   114,
     117,   117,   119,   120,   123,   124,   127,   128,   129,   130,
     133,   136,   137,   140,   141,   144,   145,   146,   147,   150,
     151,   154,   155,   158,   159,   160,   161,   164,   165,   166,
     170,   171,   172,   173,   176,   180,   180,   181,   181,   182,
     182,   183,   183,   184,   188,   189,   190,   191,   193,   194,
     196,   197,   199,   200,   203,   204,   205,   208,   209,   212,
     213,   214,   217,   218,   221,   221,   223,   224,   226,   228,
     230,   231,   232,   233,   234,   235,   238,   241,   242,   245,
     246,   248,   248,   249,   252,   253,   256,   259,   260,   263,
     266,   267,   271,   272,   273,   274,   275,   276,   279,   280,
     283,   284,   287,   288,   291,   292,   295,   296,   299,   300,
     303,   305,   307,   308,   309,   311,   312,   314,   315,   316,
     318,   320,   321,   323,   325,   326,   329,   330,   331,   334,
     335,   338,   341
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
  "stmt_list", "stmt", "$@8", "function_call", "assign_expr_list",
  "nonempty_assign_expr_list", "assign_expr", "$@9", "relop_expr", "op_or",
  "relop_term", "op_and", "relop_factor", "rel_op", "relop_expr_list",
  "nonempty_relop_expr_list", "expr", "add_op", "term", "mul_op", "factor",
  "var_ref", "var_ref_dim", "dim", "struct_tail", YY_NULL
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
      72,    72,    73,    73,    75,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    76,    77,    77,    78,
      78,    80,    79,    79,    81,    81,    82,    83,    83,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    94,    95,
      95,    96,    97
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
       2,     3,     2,     1,     0,     4,     5,     9,     7,     5,
       1,     4,     2,     1,     2,     3,     4,     1,     0,     3,
       1,     0,     4,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     4,     4,     1,     1,     2,     2,     2,     2,     1,
       5,     5,     1,     2,     2,     1,     1,     2,     2,     1,
       2,     3,     2
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
       0,     0,     0,    52,    34,    33,    35,   136,   123,   135,
     124,     0,     0,     0,   129,    71,    94,    97,   100,   113,
     117,   132,     0,     0,    15,     0,     0,    69,    68,     0,
     114,   115,    58,     0,   118,   119,     0,     0,    56,     0,
      50,    48,   109,   136,   125,   126,     0,   133,   136,   127,
     128,     0,   134,     0,    96,     0,    99,     0,   106,   107,
     104,   102,   105,   103,     0,     0,     0,     0,     0,   137,
     139,   138,    10,    13,     0,     0,    16,    17,    66,    60,
      62,    59,    46,   111,     0,   108,   109,     0,   109,     0,
     120,    95,    98,   101,   112,   116,     0,   142,   140,     0,
       8,    12,    14,    24,    18,    19,    86,     0,     0,   121,
       0,   122,   141,   136,     0,     0,     0,    74,    83,     0,
       0,     0,    26,    73,    80,     0,   132,     0,     0,    23,
     110,   130,   131,     0,   109,    88,     0,    84,     0,    11,
      25,    72,    82,     0,     0,    22,     0,     0,   136,     0,
      87,    90,    93,     0,    85,     0,     9,     0,    20,     0,
       0,     0,   109,     0,    75,    81,     0,    79,    76,     0,
       0,    89,    22,     0,    92,    88,    21,    78,     0,     0,
      77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    12,    13,   187,   159,    83,    84,
     164,   218,   188,   180,   181,    15,    16,    17,    62,    19,
      24,    59,    40,    60,    41,    21,    47,    54,    55,    56,
      31,    32,   182,   183,   196,    74,   209,   210,   211,   221,
     143,   115,    76,   117,    77,   124,   185,   145,    78,   125,
      79,    96,    80,    81,   129,   130,   131
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -167
static const yytype_int16 yypact[] =
{
    -167,    29,  -167,  -167,   279,  -167,    21,  -167,  -167,  -167,
       8,   165,  -167,  -167,   203,  -167,  -167,  -167,    57,    10,
      34,   109,    41,    88,  -167,    21,    21,    21,  -167,  -167,
      42,   150,  -167,  -167,   220,    33,    95,   154,  -167,   104,
     203,   124,   235,   248,   253,   137,    76,    95,   167,  -167,
    -167,  -167,  -167,    33,   136,   271,  -167,    33,    34,   203,
     148,    96,   167,  -167,  -167,  -167,  -167,   173,  -167,  -167,
    -167,    89,   112,   137,  -167,   197,   181,  -167,   306,   271,
    -167,    97,    25,   144,  -167,   213,   218,    90,  -167,   149,
    -167,  -167,  -167,    33,  -167,  -167,    33,   182,    95,   146,
    -167,  -167,   137,   187,  -167,  -167,   137,    97,   192,  -167,
    -167,   137,    97,     0,  -167,   137,  -167,   137,  -167,  -167,
    -167,  -167,  -167,  -167,   137,   137,   137,   137,   223,  -167,
     207,  -167,  -167,  -167,   151,   311,   214,   214,  -167,   271,
    -167,  -167,  -167,   197,   215,   210,   137,    54,   137,    84,
    -167,   181,  -167,   289,   271,  -167,   216,  -167,  -167,   188,
    -167,  -167,  -167,   137,  -167,  -167,  -167,   137,   229,  -167,
     231,  -167,  -167,    24,   243,   249,   260,  -167,  -167,    75,
     262,   226,   264,  -167,   285,   258,     5,   188,   286,   289,
     197,  -167,  -167,   137,   137,   246,   188,  -167,     1,  -167,
     264,  -167,  -167,   137,   287,   293,    91,   291,     9,   297,
     299,  -167,   197,   301,  -167,    59,  -167,   137,  -167,   264,
     264,   321,   137,   246,  -167,  -167,   228,   327,  -167,   137,
     302,  -167,   293,   264,   197,   246,  -167,  -167,   307,   264,
    -167
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,  -167,   328,  -167,  -167,  -167,   206,
     208,   114,  -167,  -164,    11,   -13,  -167,  -167,    -2,    -6,
    -167,  -167,  -167,  -167,  -167,   111,    -1,   -31,   250,   251,
    -167,   296,   168,  -166,  -167,  -151,   113,  -167,   127,  -167,
     -45,  -167,   236,  -167,   237,  -167,   -96,  -167,  -117,   -34,
     227,   -65,   230,   -68,   225,  -167,  -167
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -130
static const yytype_int16 yytable[] =
{
      75,    29,    18,   107,   112,    27,   144,   153,   184,    26,
     156,    22,    18,    20,   126,    14,   201,   114,   114,    36,
      93,   203,    89,   204,    20,   -91,    97,    20,   113,     3,
     184,   184,   213,   150,   201,   127,   184,    51,   214,    52,
      86,   102,    23,   128,    85,   184,   189,    33,    29,   184,
     168,    61,   170,   227,   228,    93,   102,    98,    45,   132,
      30,   147,   133,    93,    35,    53,   149,   237,   184,   184,
      99,   114,    35,   240,    46,    39,   114,     5,    67,    68,
      69,    70,   184,     7,     8,     9,    29,   169,   184,   126,
      10,   186,   103,   104,    71,   105,   225,     5,   207,     6,
     226,   114,    72,     7,     8,     9,    45,    73,   114,    82,
      10,    11,   197,   186,   186,   108,   109,   171,   110,   186,
      35,   106,   190,   -51,   219,    57,   230,   127,   186,    86,
      34,   101,   186,    85,   198,   128,    42,    43,    44,   -49,
      67,    68,    69,    70,   111,    37,    38,     5,   206,     6,
     212,   186,   186,     7,     8,     9,    71,    58,   215,    63,
      10,    11,    90,    91,    72,   186,     5,    92,    29,    73,
      87,   186,    25,     8,     9,    90,    91,   134,   212,    10,
     135,   142,   138,   100,   234,   160,    48,    49,   161,     5,
     212,   173,    68,    69,    70,     7,     8,     9,   174,   116,
     175,   176,    10,    11,     5,   102,     6,    71,    90,    91,
       7,     8,     9,   141,   114,    72,   136,    10,    11,   146,
      73,   137,   177,   -28,   148,   178,   157,     5,   179,   173,
      68,    69,    70,     7,     8,     9,   174,   127,   175,   176,
      10,    11,    90,    91,   163,    71,   167,   172,   166,   208,
      68,    69,    70,    72,    90,    91,    37,    50,    73,   232,
     177,   -27,   191,   178,   192,    71,   179,    67,    68,    69,
      70,    37,    64,    72,   174,   193,   175,   176,    73,    -3,
       5,   194,     6,    71,    37,    65,     7,     8,     9,    37,
      66,    72,   195,    10,    11,   202,    73,   199,   177,    94,
      95,   178,  -129,  -129,   179,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,     5,  -129,  -129,    90,    91,   205,     7,     8,
       9,  -129,   216,   217,   220,    10,   118,   119,   120,   121,
     122,   123,    90,    91,   222,   223,   224,   229,   233,   235,
     239,   162,    28,   139,    88,   165,   236,   140,   238,   200,
     231,   151,   154,     0,   152,   158,   155
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      45,    14,     4,    71,    72,    11,   102,   124,   159,    11,
     127,     3,    14,     3,    79,     4,   182,    17,    17,    20,
      54,    16,    53,   187,     3,    16,    57,     3,    73,     0,
     181,   182,   196,    33,   200,    30,   187,     4,    37,     6,
      46,    32,    34,    38,    46,   196,   163,    37,    61,   200,
     146,    40,   148,   219,   220,    89,    32,    58,    16,    34,
       3,   106,    37,    97,    30,    32,   111,   233,   219,   220,
      59,    17,    30,   239,    32,    34,    17,     1,     3,     4,
       5,     6,   233,     7,     8,     9,    99,    33,   239,   154,
      14,   159,     3,     4,    19,     6,    37,     1,   194,     3,
     217,    17,    27,     7,     8,     9,    16,    32,    17,    33,
      14,    15,    37,   181,   182,     3,     4,    33,     6,   187,
      30,    32,   167,    35,    33,    30,   222,    30,   196,   135,
      19,    35,   200,   135,   179,    38,    25,    26,    27,    35,
       3,     4,     5,     6,    32,    36,    37,     1,   193,     3,
     195,   219,   220,     7,     8,     9,    19,     3,   203,    35,
      14,    15,    26,    27,    27,   233,     1,    31,   181,    32,
       3,   239,     7,     8,     9,    26,    27,    33,   223,    14,
      36,    35,    33,    35,   229,    34,    36,    37,    37,     1,
     235,     3,     4,     5,     6,     7,     8,     9,    10,    18,
      12,    13,    14,    15,     1,    32,     3,    19,    26,    27,
       7,     8,     9,    31,    17,    27,     3,    14,    15,    32,
      32,     3,    34,    35,    32,    37,     3,     1,    40,     3,
       4,     5,     6,     7,     8,     9,    10,    30,    12,    13,
      14,    15,    26,    27,    30,    19,    36,    31,    33,     3,
       4,     5,     6,    27,    26,    27,    36,    37,    32,    31,
      34,    35,    33,    37,    33,    19,    40,     3,     4,     5,
       6,    36,    37,    27,    10,    32,    12,    13,    32,     0,
       1,    32,     3,    19,    36,    37,     7,     8,     9,    36,
      37,    27,    32,    14,    15,    37,    32,    35,    34,    28,
      29,    37,    17,    18,    40,    20,    21,    22,    23,    24,
      25,    26,     1,    28,    29,    26,    27,    31,     7,     8,
       9,    36,    35,    30,    33,    14,    20,    21,    22,    23,
      24,    25,    26,    27,    37,    36,    35,    16,    11,    37,
      33,   135,    14,    93,    48,   137,   232,    96,   235,   181,
     223,   115,   125,    -1,   117,   130,   126
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
       6,    19,    27,    32,    76,    81,    83,    85,    89,    91,
      93,    94,    33,    49,    50,    59,    60,     3,    72,    68,
      26,    27,    31,    90,    28,    29,    92,    68,    67,    55,
      35,    35,    32,     3,     4,     6,    32,    94,     3,     4,
       6,    32,    94,    81,    17,    82,    18,    84,    20,    21,
      22,    23,    24,    25,    86,    90,    92,    30,    38,    95,
      96,    97,    34,    37,    33,    36,     3,     3,    33,    69,
      70,    31,    35,    81,    87,    88,    32,    81,    32,    81,
      33,    83,    85,    89,    91,    93,    89,     3,    95,    48,
      34,    37,    50,    30,    51,    51,    33,    36,    87,    33,
      87,    33,    31,     3,    10,    12,    13,    34,    37,    40,
      54,    55,    73,    74,    76,    87,    94,    47,    53,    89,
      81,    33,    33,    32,    32,    32,    75,    37,    81,    35,
      73,    74,    37,    16,    54,    31,    81,    87,     3,    77,
      78,    79,    81,    54,    37,    81,    35,    30,    52,    33,
      33,    80,    37,    36,    35,    37,    89,    74,    74,    16,
      87,    79,    31,    11,    81,    37,    52,    74,    77,    33,
      74
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
#line 103 "parser.y"
    { init_all(); strcpy(int_type.real_type, "int"); strcpy(string_type.real_type, "string"); strcpy(float_type.real_type, "float"); }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 103 "parser.y"
    { print_vars(); print_types(); print_funcs(); print_structs(); print_all_asm(); close_asm_file();}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    {func_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].Param_List)); inc_nesting();}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 114 "parser.y"
    {dec_nesting();}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 117 "parser.y"
    {func_decl((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), NULL); inc_nesting();}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 117 "parser.y"
    {dec_nesting();}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 119 "parser.y"
    {func_decl((yyvsp[(1) - (6)].str), (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].Param_List));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 120 "parser.y"
    {func_decl((yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), NULL);}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 123 "parser.y"
    { (yyval.Param_List)->next=(yyvsp[(3) - (3)].Param_List); }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 127 "parser.y"
    { (yyval.Param_List)=func_param_decl ( (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str), 0, get_nesting()+1 ); }
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 128 "parser.y"
    { (yyval.Param_List)=NULL; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 129 "parser.y"
    { (yyval.Param_List)=func_param_decl ( (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].ival), get_nesting()+1 ); }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 130 "parser.y"
    { (yyval.Param_List)=NULL; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 133 "parser.y"
    {(yyval.ival)=(yyvsp[(4) - (4)].ival)+1;}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 136 "parser.y"
    {(yyval.ival)=(yyvsp[(4) - (4)].ival)+1;}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 137 "parser.y"
    {(yyval.ival)=0;}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 158 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 159 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 160 "parser.y"
    { type_def((yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].ID_List), get_nesting()); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 164 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 165 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 166 "parser.y"
    { add_var_list((yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].ID_List), get_nesting()); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 170 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 171 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 172 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 173 "parser.y"
    {(yyval.str)="error";}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 176 "parser.y"
    {(yyval.str)=build_struct_type( (yyvsp[(2) - (2)].str) );}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 180 "parser.y"
    {inc_nesting();}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 180 "parser.y"
    {struct_decl( (yyvsp[(1) - (5)].str) ); dec_nesting(); (yyval.str)=(yyvsp[(1) - (5)].str);}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 181 "parser.y"
    {inc_nesting();}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 181 "parser.y"
    {struct_decl( get_random_name() ); dec_nesting(); (yyval.str)=get_random_name();}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    {inc_nesting();}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 182 "parser.y"
    {struct_decl( (yyvsp[(1) - (4)].str) ); dec_nesting(); (yyval.str)=(yyvsp[(1) - (4)].str);}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    {inc_nesting();}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 183 "parser.y"
    {struct_decl( get_random_name() ); dec_nesting(); (yyval.str)=get_random_name();}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 184 "parser.y"
    {(yyval.str)=(yyvsp[(1) - (1)].str);}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 188 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (1)].str), 0); }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 189 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(3) - (3)].str), 0); (yyval.ID_List)->next=(yyvsp[(1) - (3)].ID_List); }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 190 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].ival)); (yyval.ID_List)->next=(yyvsp[(1) - (4)].ID_List); }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 191 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival)); }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 193 "parser.y"
    {(yyval.ival)=1;}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 194 "parser.y"
    {(yyval.ival)=(yyvsp[(1) - (4)].ival)+1;}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 208 "parser.y"
    {(yyval.ID_List)=(yyvsp[(1) - (1)].ID_List);}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 209 "parser.y"
    { (yyvsp[(3) - (3)].ID_List)->next=(yyvsp[(1) - (3)].ID_List) ; (yyval.ID_List)=(yyvsp[(3) - (3)].ID_List); }
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 212 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (1)].str), 0); }
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 213 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].ival)); }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 214 "parser.y"
    { (yyval.ID_List)=var_decl((yyvsp[(1) - (3)].str), 0); emit_var_assign((yyvsp[(1) - (3)].str)); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    {inc_nesting();}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 221 "parser.y"
    {dec_nesting();}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 231 "parser.y"
    { check_array_dimmension( (yyvsp[(1) - (4)].EXPR_type) ); check_assign_types((yyvsp[(1) - (4)].EXPR_type), (yyvsp[(3) - (4)].EXPR_type)); emit_var_assign((yyvsp[(1) - (4)].EXPR_type).name);}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 234 "parser.y"
    { type_t temp; strcpy(temp.real_type, "void"); check_func_return (temp); emit_return(); }
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 235 "parser.y"
    { check_func_return((yyvsp[(2) - (3)].EXPR_type)); emit_return();}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 238 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].EXPR_type).param_count ); emit_func_call((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].EXPR_type).param_count, (yyvsp[(3) - (4)].EXPR_type).real_type); }
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 248 "parser.y"
    {process_id((yyvsp[(1) - (1)].str));}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 248 "parser.y"
    {emit_var_assign((yyvsp[(1) - (4)].str));}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 252 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 253 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival));  }
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 256 "parser.y"
    { emit_move_to_live(); (yyval.ival)=4; }
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 259 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 260 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) );  emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 263 "parser.y"
    { emit_move_to_live(); (yyval.ival)=5; }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 266 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 267 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival));}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 271 "parser.y"
    { emit_move_to_live(); (yyval.ival)=6; }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 272 "parser.y"
    { emit_move_to_live(); (yyval.ival)=7; }
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 273 "parser.y"
    { emit_move_to_live(); (yyval.ival)=8; }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 274 "parser.y"
    { emit_move_to_live(); (yyval.ival)=9; }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 275 "parser.y"
    { emit_move_to_live(); (yyval.ival)=10; }
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 276 "parser.y"
    { emit_move_to_live(); (yyval.ival)=11; }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 279 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type) ;  (yyval.EXPR_type).param_count=(yyvsp[(1) - (1)].EXPR_type).param_count; }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 280 "parser.y"
    { (yyval.EXPR_type).param_count=0; }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 283 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; (yyval.EXPR_type).param_count = (yyvsp[(1) - (3)].EXPR_type).param_count + 1; emit_move_to_live(); }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 284 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type) ; (yyval.EXPR_type).param_count = 1; emit_move_to_live(); }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 287 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 288 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 291 "parser.y"
    { emit_move_to_live(); (yyval.ival)=2; }
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 292 "parser.y"
    { emit_move_to_live(); (yyval.ival)=3; }
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 295 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (3)].EXPR_type) ; check_op_types ( (yyvsp[(1) - (3)].EXPR_type), (yyvsp[(3) - (3)].EXPR_type) ); emit_op((yyvsp[(2) - (3)].ival)); }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 296 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 299 "parser.y"
    { emit_move_to_live(); (yyval.ival)=0; }
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 300 "parser.y"
    { emit_move_to_live();  (yyval.ival)=1; }
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 303 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(2) - (3)].EXPR_type); }
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 305 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(3) - (4)].EXPR_type); emit_not();}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 307 "parser.y"
    { (yyval.EXPR_type) = (yyvsp[(3) - (4)].EXPR_type); emit_negate();}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 308 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(1) - (1)].ival)); }
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 309 "parser.y"
    { emit_const_loadf((yyvsp[(1) - (1)].fval)); printf("floating point %f\n", (yyvsp[(1) - (1)].fval)); (yyval.EXPR_type) = float_type; }
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 311 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(2) - (2)].ival)); emit_not(); }
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 312 "parser.y"
    { (yyval.EXPR_type) = float_type; emit_const_loadf((yyvsp[(2) - (2)].fval)); emit_not(); }
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 314 "parser.y"
    { (yyval.EXPR_type) = int_type; emit_const_loadi((yyvsp[(2) - (2)].ival)); emit_negate(); }
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 315 "parser.y"
    { (yyval.EXPR_type) = float_type; emit_const_loadf((yyvsp[(2) - (2)].fval)); emit_negate(); }
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 316 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); }
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 318 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].EXPR_type).param_count ); emit_not(); }
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 320 "parser.y"
    { (yyval.EXPR_type) = check_func_call( (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].EXPR_type).param_count ); emit_negate(); }
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 321 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(1) - (1)].EXPR_type); check_array_dimmension((yyvsp[(1) - (1)].EXPR_type)); }
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 323 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(2) - (2)].EXPR_type); check_array_dimmension((yyvsp[(2) - (2)].EXPR_type)); emit_not();}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 325 "parser.y"
    { (yyval.EXPR_type)=(yyvsp[(2) - (2)].EXPR_type); check_array_dimmension((yyvsp[(2) - (2)].EXPR_type)); emit_negate();}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 326 "parser.y"
    { emit_load_string((yyvsp[(1) - (1)].str)); (yyval.EXPR_type)=string_type;}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 329 "parser.y"
    {process_id((yyvsp[(1) - (1)].str)); (yyval.EXPR_type)=check_id_type((yyvsp[(1) - (1)].str)); (yyval.EXPR_type).param_count=0; (yyval.EXPR_type).dim_count_struct=-1; emit_load_var((yyvsp[(1) - (1)].str)); }
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 330 "parser.y"
    { (yyvsp[(1) - (2)].EXPR_type).param_count=(yyvsp[(2) - (2)].ival); (yyval.EXPR_type)=(yyvsp[(1) - (2)].EXPR_type); }
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 331 "parser.y"
    { check_array_dimmension((yyvsp[(1) - (2)].EXPR_type)); (yyval.EXPR_type)=struct_ref((yyvsp[(1) - (2)].EXPR_type).name, (yyvsp[(2) - (2)].str)); (yyval.EXPR_type).dim_count_struct = array_dimmension_struct((yyval.EXPR_type), (yyvsp[(1) - (2)].EXPR_type).name); (yyval.EXPR_type).param_count=0; }
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 334 "parser.y"
    { (yyval.ival)=1; }
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 335 "parser.y"
    { (yyval.ival)=(yyvsp[(2) - (2)].ival)+1; }
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 338 "parser.y"
    { check_dim_type((yyvsp[(2) - (3)].EXPR_type)); }
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 341 "parser.y"
    {(yyval.str)=(yyvsp[(2) - (2)].str);}
    break;


/* Line 1787 of yacc.c  */
#line 2275 "parser.tab.c"
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
#line 343 "parser.y"

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
