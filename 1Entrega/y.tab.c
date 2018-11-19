
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define TERCETOS "intermedia.txt"

int yystopparser=0;
FILE  *yyin;
FILE* pf_TS;
FILE* pf_asm;
 typedef struct{
        int posicion;
        char nombre[30];
        char tipo[20];
        char valor[100];
        int longitud;
        } TS_reg;
    
 TS_reg tabla_simbSinta[100];
 TS_reg ts_asm[100];


char listaDeTipos[][100]={"."};
int listaDeIDs[100];

int cant_entradaSint = 0;
int totalVariables = 0;
int cantidadTipos=0;              
int cantidadIDs=0;     
char* yytext;
char stringVarAux[5];

void agregarTipo(char * );
void agregarIDs(char * );


int busca_en_TSinta(char*);
void busca_Var_Existe(char*);
int graba_TSinta();
int inserta_TSinta(char*,char*);

// TERCETO DECLARACIONES
typedef struct terceto{
  char* operacion[5];
  int t1, t2;
  int numeroTerceto;
} t_terceto;

//Variables para tercetos
t_terceto  asignacion_terceto,
      expresion_terceto, 
      termino_terceto, 
      factor_terceto, 
      concatenacion_terceto,
      factor_terceto_aux,
      expresion_terceto_aux,
      expresion_between_aux,
      expresion_sum_terceto,
      expresion_cont_terceto,
      expresion_cont_terceto_uno,
      condicion_terceto;
t_terceto *vectorTercetos;
//char *vectorVariablesAssembler;
int indiceTerceto = 0;
char op_comparacion[5];


t_terceto crearTerceto(char*,int,int);
t_terceto* buscarTerceto(t_terceto t);
void mostrarTerceto(t_terceto terceto);
void escribirArchivoTercetos();
void escribirTerceto(t_terceto t1,FILE* arch);
void crearTercetoSalto(char*);

//PILA
typedef struct s_nodo {
    int valor;
    struct s_nodo *sig;
} t_nodo;
typedef t_nodo* t_pila;

t_pila pila;
t_pila comparacion; //Indica que operador de comparacion se uso
t_pila pila_condicion; //Apila los tipos de condicion (and, or, not) cuando hay anidamiento

void insertar_pila (t_pila*, int);
int sacar_pila(t_pila*);
void crear_pila(t_pila*);
void destruir_pila(t_pila*);

//ASSEMBLER
int grabar_archivo_asm();
int obtenerTablaSimbolosCompleta();
char* buscaTipoEnTS(char* nombre);
void getCodigo(char* operador);
int esOperacion(char *operacion);



/* Line 189 of yacc.c  */
#line 176 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ENDP = 259,
     DECVAR = 260,
     ENDDEC = 261,
     CONST_REAL = 262,
     CONST_STR = 263,
     REAL = 264,
     STRING = 265,
     IF = 266,
     THEN = 267,
     ELSE = 268,
     ENDIF = 269,
     WHILE = 270,
     ENDW = 271,
     OP_LOG = 272,
     OP_NOT = 273,
     ID = 274,
     OP_COMPARACION = 275,
     OP_AS = 276,
     OP_SURES = 277,
     OP_MULTDIV = 278,
     COMA = 279,
     P_A = 280,
     P_C = 281,
     C_A = 282,
     C_C = 283,
     READ = 284,
     WRITE = 285,
     BETWEEN = 286,
     AVERAGE = 287,
     PCOMA = 288
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define ENDP 259
#define DECVAR 260
#define ENDDEC 261
#define CONST_REAL 262
#define CONST_STR 263
#define REAL 264
#define STRING 265
#define IF 266
#define THEN 267
#define ELSE 268
#define ENDIF 269
#define WHILE 270
#define ENDW 271
#define OP_LOG 272
#define OP_NOT 273
#define ID 274
#define OP_COMPARACION 275
#define OP_AS 276
#define OP_SURES 277
#define OP_MULTDIV 278
#define COMA 279
#define P_A 280
#define P_C 281
#define C_A 282
#define C_C 283
#define READ 284
#define WRITE 285
#define BETWEEN 286
#define AVERAGE 287
#define PCOMA 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 103 "Sintactico.y"

  int intval;
  char * doubleval;
  char *str_val;



/* Line 214 of yacc.c  */
#line 286 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 298 "y.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   103

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    10,    11,    16,    18,    21,    22,
      27,    29,    31,    33,    37,    38,    41,    44,    46,    48,
      50,    52,    54,    57,    60,    63,    64,    65,    66,    67,
      82,    83,    91,    95,    97,    98,   104,   108,   114,   115,
     124,   126,   130,   133,   134,   135,   141,   143,   145,   146,
     147,   153,   155,   156,   161,   163,   165,   167
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    -1,     3,    36,    37,    44,     4,    -1,
      -1,     5,    38,    39,     6,    -1,    40,    -1,    39,    40,
      -1,    -1,    43,    41,    33,    42,    -1,     9,    -1,    10,
      -1,    19,    -1,    43,    24,    19,    -1,    -1,    45,    46,
      -1,    44,    46,    -1,    56,    -1,    59,    -1,    58,    -1,
      47,    -1,    53,    -1,    29,    19,    -1,    30,     8,    -1,
      30,    19,    -1,    -1,    -1,    -1,    -1,    31,    49,    25,
      65,    50,    24,    27,    65,    51,    33,    65,    52,    28,
      26,    -1,    -1,    32,    54,    25,    27,    55,    28,    26,
      -1,    55,    24,    65,    -1,    65,    -1,    -1,    15,    61,
      57,    44,    16,    -1,    19,    21,    65,    -1,    11,    61,
      12,    44,    14,    -1,    -1,    11,    61,    12,    44,    60,
      13,    44,    14,    -1,    62,    -1,    62,    17,    62,    -1,
      18,    62,    -1,    -1,    -1,    65,    63,    20,    64,    65,
      -1,    48,    -1,    68,    -1,    -1,    -1,    65,    66,    22,
      67,    68,    -1,    70,    -1,    -1,    68,    23,    69,    70,
      -1,    19,    -1,     7,    -1,     8,    -1,    53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   137,   137,   137,   141,   141,   148,   149,   152,   152,
     155,   156,   159,   160,   163,   163,   163,   165,   165,   165,
     165,   165,   167,   167,   167,   169,   170,   171,   172,   169,
     177,   177,   184,   195,   214,   214,   216,   227,   236,   235,
     252,   253,   254,   257,   258,   257,   265,   268,   269,   270,
     269,   274,   275,   275,   280,   285,   291,   295
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ENDP", "DECVAR", "ENDDEC",
  "CONST_REAL", "CONST_STR", "REAL", "STRING", "IF", "THEN", "ELSE",
  "ENDIF", "WHILE", "ENDW", "OP_LOG", "OP_NOT", "ID", "OP_COMPARACION",
  "OP_AS", "OP_SURES", "OP_MULTDIV", "COMA", "P_A", "P_C", "C_A", "C_C",
  "READ", "WRITE", "BETWEEN", "AVERAGE", "PCOMA", "$accept", "programa",
  "$@1", "est_declaracion", "$@2", "declaraciones", "declaracion", "$@3",
  "type", "lista_var", "bloque", "$@4", "sentencia", "teclado",
  "reglabetween", "$@5", "$@6", "$@7", "$@8", "reglaaverage", "$@9",
  "listaexpresiones", "ciclow", "$@10", "asignacion", "seleccion", "$@11",
  "condicion", "comparacion", "$@12", "$@13", "expresion", "$@14", "$@15",
  "termino", "$@16", "factor", 0
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
     285,   286,   287,   288
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    36,    35,    38,    37,    39,    39,    41,    40,
      42,    42,    43,    43,    45,    44,    44,    46,    46,    46,
      46,    46,    47,    47,    47,    49,    50,    51,    52,    48,
      54,    53,    55,    55,    57,    56,    58,    59,    60,    59,
      61,    61,    61,    63,    64,    62,    62,    65,    66,    67,
      65,    68,    69,    68,    70,    70,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     5,     0,     4,     1,     2,     0,     4,
       1,     1,     1,     3,     0,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     2,     0,     0,     0,     0,    14,
       0,     7,     3,     1,     0,     5,     3,     5,     0,     8,
       1,     3,     2,     0,     0,     5,     1,     1,     0,     0,
       5,     1,     0,     4,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     4,    14,     0,     0,     0,
      12,     0,     6,     8,     3,     0,     0,     0,     0,     0,
      30,    16,    20,    21,    17,    19,    18,    15,     5,     7,
       0,     0,    55,    56,     0,    54,    25,    46,    57,     0,
      40,    43,    47,    51,    34,     0,    22,    23,    24,     0,
      13,     0,    42,     0,    14,     0,     0,     0,    52,    14,
      36,     0,    10,    11,     9,     0,    38,    41,    44,    49,
       0,     0,     0,    26,    37,     0,     0,     0,    53,    35,
       0,    33,     0,    14,    45,    50,     0,     0,     0,     0,
      32,    31,     0,    39,    27,     0,     0,    28,     0,     0,
      29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    11,    12,    31,    64,    13,
       8,     9,    21,    22,    37,    53,    82,    95,    98,    38,
      49,    80,    24,    59,    25,    26,    75,    39,    40,    56,
      76,    41,    57,    77,    42,    70,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int8 yypact[] =
{
      10,   -52,    19,     0,   -52,   -52,   -52,     9,     5,    67,
     -52,    21,   -52,    18,   -52,    -1,    -1,    23,    27,     2,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
      29,    26,   -52,   -52,     7,   -52,   -52,   -52,   -52,    42,
      47,    45,    46,   -52,   -52,     4,   -52,   -52,   -52,    49,
     -52,    52,   -52,    54,   -52,     7,    57,    62,   -52,   -52,
      45,    56,   -52,   -52,   -52,     4,    36,   -52,   -52,   -52,
       4,    41,     4,    45,   -52,    72,     4,     4,   -52,   -52,
      17,    45,    63,   -52,    45,    46,     4,    66,    68,    61,
      45,   -52,     4,   -52,    45,    55,     4,    45,    70,    74,
     -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -52,   -52,   -52,    78,   -52,   -52,   -52,
     -51,   -52,    85,   -52,   -52,   -52,   -52,   -52,   -52,    -8,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,    86,   -30,   -52,
     -52,   -43,   -52,   -52,    24,   -52,    33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int8 yytable[] =
{
      23,    23,    60,    66,    52,     5,    32,    33,    71,    14,
      47,    32,    33,     1,    32,    33,    15,    34,    35,     4,
      16,    48,    73,    35,    17,    67,    35,    28,    10,    81,
      36,    20,    89,    84,    18,    19,    20,    20,    36,    20,
      10,    86,    30,    90,    45,    87,    46,    15,    50,    94,
      74,    16,    15,    97,    54,    17,    16,    79,    23,    51,
      17,    62,    63,    23,    55,    18,    19,   -48,    20,    58,
      18,    19,    15,    20,    61,    93,    16,    68,    15,    65,
      17,    23,    16,    72,    69,    83,    17,    88,    96,    29,
      18,    19,    91,    20,    27,    92,    18,    19,    99,    20,
     100,    85,    44,    78
};

static const yytype_uint8 yycheck[] =
{
       8,     9,    45,    54,    34,     5,     7,     8,    59,     4,
       8,     7,     8,     3,     7,     8,    11,    18,    19,     0,
      15,    19,    65,    19,    19,    55,    19,     6,    19,    72,
      31,    32,    83,    76,    29,    30,    32,    32,    31,    32,
      19,    24,    24,    86,    21,    28,    19,    11,    19,    92,
      14,    15,    11,    96,    12,    19,    15,    16,    66,    33,
      19,     9,    10,    71,    17,    29,    30,    22,    32,    23,
      29,    30,    11,    32,    25,    14,    15,    20,    11,    25,
      19,    89,    15,    27,    22,    13,    19,    24,    33,    11,
      29,    30,    26,    32,     9,    27,    29,    30,    28,    32,
      26,    77,    16,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    35,    36,     0,     5,    37,    38,    44,    45,
      19,    39,    40,    43,     4,    11,    15,    19,    29,    30,
      32,    46,    47,    53,    56,    58,    59,    46,     6,    40,
      24,    41,     7,     8,    18,    19,    31,    48,    53,    61,
      62,    65,    68,    70,    61,    21,    19,     8,    19,    54,
      19,    33,    62,    49,    12,    17,    63,    66,    23,    57,
      65,    25,     9,    10,    42,    25,    44,    62,    20,    22,
      69,    44,    27,    65,    14,    60,    64,    67,    70,    16,
      55,    65,    50,    13,    65,    68,    24,    28,    24,    44,
      65,    26,    27,    14,    65,    51,    33,    65,    52,    28,
      26
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 137 "Sintactico.y"
    {printf(" Inicia COMPILADOR\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 138 "Sintactico.y"
    {printf(" Fin COMPILADOR ok\n"); graba_TSinta(); escribirArchivoTercetos(); grabar_archivo_asm(); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {printf("     DECLARACIONES\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 141 "Sintactico.y"
    {printf(" Fin de las Declaraciones\n"); 
                                                                  
                                                                  }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 152 "Sintactico.y"
    {printf("lista de var\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 153 "Sintactico.y"
    { printf("TIPO\n" );}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 155 "Sintactico.y"
    {agregarTipo(yytext);
         }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 156 "Sintactico.y"
    {agregarTipo(yytext);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {agregarIDs(yytext); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 160 "Sintactico.y"
    {agregarIDs(yytext); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 163 "Sintactico.y"
    {printf(" Inicia BLOQUE\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 169 "Sintactico.y"
    {printf(" Regla BETWEEN\n");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 170 "Sintactico.y"
    {expresion_terceto_aux = expresion_terceto;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {expresion_between_aux = crearTerceto(">=", expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 172 "Sintactico.y"
    {crearTerceto("==",expresion_between_aux.numeroTerceto,crearTerceto("<=", expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto).numeroTerceto);
                          }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 177 "Sintactico.y"
    {printf(" Regla AVERAGE\n");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 177 "Sintactico.y"
    { 
               
                t_terceto t_div = crearTerceto("/", expresion_sum_terceto.numeroTerceto, expresion_cont_terceto.numeroTerceto);
                t_terceto t_avg = crearTerceto("avg", -1, -1);
                crearTerceto("=",t_avg.numeroTerceto,t_div.numeroTerceto);

                }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 184 "Sintactico.y"
    {
                          
                //Sumamos a Sum y asignamos el valor
                t_terceto t_suma = crearTerceto("+", expresion_sum_terceto.numeroTerceto, expresion_terceto.numeroTerceto); 
                crearTerceto("=", expresion_sum_terceto.numeroTerceto, t_suma.numeroTerceto); 
                
                //lo asignamos a las estructuras
                t_terceto t_cont = crearTerceto("+",expresion_cont_terceto.numeroTerceto, expresion_cont_terceto_uno.numeroTerceto);
                crearTerceto("=",expresion_cont_terceto.numeroTerceto,t_cont.numeroTerceto);
                
                }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 195 "Sintactico.y"
    { 
                  
                //expresion_terceto_aux = expresion_terceto;
                //Creo las variables 
                expresion_sum_terceto = crearTerceto("sum",-1,-1); 
                expresion_cont_terceto = crearTerceto("cont",-1,-1); 

                //Sumamos a Sum y asignamos el valor
                t_terceto t_suma = crearTerceto("+", expresion_sum_terceto.numeroTerceto, expresion_terceto.numeroTerceto); 
                crearTerceto("=", expresion_sum_terceto.numeroTerceto, t_suma.numeroTerceto); 
                
                //Creamos el 1 para poder incrementar y lo asignamos a las estructuras
                expresion_cont_terceto_uno = crearTerceto("1",-1,-1);
                t_terceto t_cont = crearTerceto("+",expresion_cont_terceto.numeroTerceto, expresion_cont_terceto_uno.numeroTerceto);
                crearTerceto("=",expresion_cont_terceto.numeroTerceto,t_cont.numeroTerceto);
                
                }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 214 "Sintactico.y"
    { printf("     CONDICION DEL WHILE\n");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 216 "Sintactico.y"
    {
              busca_Var_Existe((yyvsp[(1) - (3)].str_val));
              //printf("    ASIGNACION\n");
              //printf("La variable recuperada es : %s y el UNO %s y %f\n",yytext , $<str_val>1,$<doubleval>1);
              t_terceto tAux = crearTerceto((yyvsp[(1) - (3)].str_val),-1,-1); 
              crearTerceto(":=", tAux.numeroTerceto, expresion_terceto.numeroTerceto);
              //mostrarTerceto(tAux);
            }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 229 "Sintactico.y"
    {printf("     IF\t TERCETOS fin de parte TRUE %d \n", indiceTerceto);
            int numT = sacar_pila(&comparacion);
            printf("\n\n\n TERCET correcto? %s\n\n\n", vectorTercetos[numT].operacion);
            vectorTercetos[numT].t1 = indiceTerceto;

          }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 236 "Sintactico.y"
    {
              crearTerceto("JMP",-1,-1);
              printf("     IF\t TERCETOS fin de parte TRUE %d \n", indiceTerceto);
            int numT = sacar_pila(&comparacion);
            printf("\n\n\n TERCET correcto? %s\n\n\n", vectorTercetos[numT].operacion);
            vectorTercetos[numT].t1 = indiceTerceto;
            insertar_pila(&comparacion, indiceTerceto-1);
          }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 245 "Sintactico.y"
    {printf("     IF con ELSE fin de parte FALSE %d \n", indiceTerceto);
            int numT = sacar_pila(&comparacion);
            printf("\n\n\n TERCET FALSE correcto? %s\n\n\n", vectorTercetos[numT].operacion);
            vectorTercetos[numT].t1 = indiceTerceto;
          }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 257 "Sintactico.y"
    {expresion_terceto_aux = expresion_terceto;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 258 "Sintactico.y"
    {strcpy(stringVarAux,yytext);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 259 "Sintactico.y"
    {crearTerceto(stringVarAux, expresion_terceto_aux.numeroTerceto, expresion_terceto.numeroTerceto);
           printf("IF\t TERCETOS fin de condicion %d \n", indiceTerceto);
           insertar_pila(&comparacion, indiceTerceto);
           crearTercetoSalto(stringVarAux);

         }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 268 "Sintactico.y"
    {expresion_terceto = termino_terceto;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 269 "Sintactico.y"
    {expresion_terceto = termino_terceto;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 270 "Sintactico.y"
    {strcpy(stringVarAux,yytext);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 271 "Sintactico.y"
    {expresion_terceto = crearTerceto(stringVarAux, expresion_terceto.numeroTerceto, termino_terceto.numeroTerceto);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 274 "Sintactico.y"
    {termino_terceto = factor_terceto;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 275 "Sintactico.y"
    {strcpy(stringVarAux,yytext);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 276 "Sintactico.y"
    {termino_terceto = crearTerceto(stringVarAux, termino_terceto.numeroTerceto, factor_terceto.numeroTerceto);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 280 "Sintactico.y"
    {
          busca_Var_Existe(yytext);
          printf("LLEGO EL LEXEMA DEL ID  : %s\n",yytext);
          factor_terceto = crearTerceto((yyvsp[(1) - (1)].str_val),-1,-1);
          }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 285 "Sintactico.y"
    {
          
          printf("PASO UNA CONSTANTE REAL %s\n", (yyvsp[(1) - (1)].doubleval));
          factor_terceto = crearTerceto((yyvsp[(1) - (1)].doubleval),-1,-1);
          
          }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 292 "Sintactico.y"
    {
          printf("PASO UNA CONSTANTE STRING ");
          }
    break;



/* Line 1455 of yacc.c  */
#line 1916 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 298 "Sintactico.y"

int main(int argc,char *argv[])
{
  fflush(stdout);

  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\n \n \n \n \n \nNo se puede abrir el archivo: %s\n \n  \n  \n \n \n \n \n \n ", argv[1]);
  }
  else
  {
  //TERCETO
  //openFile(TERCETOS, &intermedia);
   crear_pila(&comparacion);
   printf("cree la pila\n");
	yyparse();
  }
  fclose(yyin);
  return 0;
}

int yyerror(char const *line)
{
  printf("Syntax Error\n");   
  exit (1);
}

/**********************TIPO y IDS***************************/
void agregarTipo(char * tipo)
{
  for (int i = 0; i < cantidadIDs; i++)
  {
   
    strcpy(tabla_simbSinta[ listaDeIDs[i] ].tipo, tipo);
    listaDeIDs[i] = 0;
  }
  cantidadIDs=0;


}

void agregarIDs(char * idValue)
{
  listaDeIDs[cantidadIDs] = inserta_TSinta("ID", idValue);
  cantidadIDs++;
}



//Buscamos si fue creada la variable
int busca_en_TSinta(char* nombre)
{
    int i;
    for(i = 0; i<cant_entradaSint; i++)
    {
          if(!strcmp(tabla_simbSinta[i].nombre, nombre))
          {
                 return i;
          }
    }
    
    return -1;
}
//Buscamos si fue creada la variable para usarla
void busca_Var_Existe(char* var)
{int i;
    
    for(i = 0; i<cant_entradaSint; i++)
    {
      
          if(!strcmp(tabla_simbSinta[i].nombre, var))
          {
            if(!strcmp(tabla_simbSinta[i].tipo,"REAL")){
              return;  
            }else{
              printf("\n Tipo Incompatible: %s\n", var);
            yyerror(var);
            }
            
          }
    }
    printf("Variable no declarada: %s\n\n", var);
            yyerror(var);
}

int inserta_TSinta(char* tipo,char* valor)
{
   if((busca_en_TSinta(yytext)) == -1)
     {
    TS_reg reg;
    strcpy(reg.nombre, yytext);
    strcpy(reg.tipo, tipo);
    strcpy(reg.valor, valor);
    reg.longitud = strlen(yytext);
    reg.posicion = cant_entradaSint;
    tabla_simbSinta[cant_entradaSint++] = reg;
    
    return cant_entradaSint-1;
   }
}

int graba_TSinta()
{
    
     int i;
     char* TS_file = "ts.txt";
     
     if((pf_TS = fopen(TS_file, "a+")) == NULL)
     {
               printf("\nE \nE \nE \nE \nE \nE \nE \nE Error al grabar la tabla de simbolos \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE ");
               exit(1);
     }
     
     //fprintf(pf_TS, "POSICION \t\t\t NOMBRE \t\t TIPO \t\t VALOR \t\t LONGITUD \n");
     
      for(i = 0; i < cant_entradaSint; i++)
      {
           fprintf(pf_TS,"%d\t\t\t\t%s\t\t\t", tabla_simbSinta[i].posicion, tabla_simbSinta[i].nombre);
           
          
            if(tabla_simbSinta[i].tipo != NULL)
               fprintf(pf_TS,"%s\t\t\t", tabla_simbSinta[i].tipo);
           
          
            if(tabla_simbSinta[i].valor != NULL)
               fprintf(pf_TS,"%s\t\t\t", tabla_simbSinta[i].valor);
           
            fprintf(pf_TS,"%d\n", tabla_simbSinta[i].longitud);
      }    
     fclose(pf_TS);
}


//TERCETOS
//Crea el terceto con los indices de los tercetos. Si no existen tiene -1
t_terceto crearTerceto(char* operacion,int t1,int t2){
  t_terceto result;
  strcpy(result.operacion, operacion);
  result.t1 = t1;
  result.t2 = t2; 
   result.numeroTerceto = indiceTerceto++;
    vectorTercetos = (t_terceto*) realloc(vectorTercetos, sizeof(t_terceto) * indiceTerceto);
    vectorTercetos[indiceTerceto-1] = result;
	
  //}
  return result;
}

void crearTercetoSalto(char* operador){
  if (strcmp(operador,"==") == 0) {
    crearTerceto("JNE",-1,-1);
  } else if (strcmp(operador,"><") == 0) {
    crearTerceto("JE",-1,-1);
  } else if (strcmp(operador,"<") == 0) {
    crearTerceto("JGE",-1,-1);
  } else if (strcmp(operador,">") == 0) {
    crearTerceto("JLE",-1,-1);
  } else if (strcmp(operador,">=") == 0) {
    crearTerceto("JLT",-1,-1);
  } else if (strcmp(operador,"<=") == 0) {
    crearTerceto("JGT",-1,-1);
  } else {
    return 0;
  }
}


//Muestra el Terceto
void mostrarTerceto(t_terceto t){
  //printf("terceto de operacion: [%d] %d %s %d\n", t.numeroTerceto, t.t1, t.operacion, t.t2);
}


//Busca un terceto en el vector de tercetos
t_terceto* buscarTerceto(t_terceto t){
  int i;
  for (i = 0; i < indiceTerceto; ++i) 
    if(strcmp(vectorTercetos[i].operacion, t.operacion) == 0 && vectorTercetos[i].t1 == -1 && vectorTercetos[i].t2 == -1)
      return &(vectorTercetos[i]); 
  return NULL;
}

//Escribe todos los Tercetos
void escribirArchivoTercetos(){
  int i;
  FILE* tercetos = fopen(TERCETOS, "w");
  for(i = 0; i < indiceTerceto; i++)
    escribirTerceto(vectorTercetos[i],tercetos);
  fclose(tercetos);
}

//Escribe un terceto en el archivo
void escribirTerceto(t_terceto t,FILE* arch){
  mostrarTerceto(t);
  if(strcmp(t.operacion, "BI")==0)
    fprintf(arch, "[%d] (%s,[%d],-)\n", t.numeroTerceto, t.operacion, t.t2);
  else if(t.t1 == -1 && t.t2 == -1)
    fprintf(arch, "[%d] (%s,_,_)\n", t.numeroTerceto, t.operacion);
  else if(t.t2 == -1)
    fprintf(arch, "[%d] (%s,[%d],_)\n", t.numeroTerceto, t.operacion, t.t1);
  else
    fprintf(arch, "[%d] (%s,[%d],[%d])\n", t.numeroTerceto, t.operacion, t.t1, t.t2);
  
}



int grabar_archivo_asm()
{
	printf("Generando ASSEMBLER\n");
    int i;
    char aux_cte[31];
	FILE* pf_asm;
	char* tipo;
	char operandoresASM[100][100];
	
	//Leo el archivo de la tabla de simbolos para poder tener las constantes
	if(obtenerTablaSimbolosCompleta()==1)
	{
		printf("No se pudo obtener las variables de la tabla de simbolos.\n");
		exit(1);
	}
	
	if((pf_asm = fopen("Final.txt", "w")) == NULL ){
		printf("\nE \nE \nE \nE \nE \nE \nE \nE Error al generar ASSEMBLER \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE \nE ");
		exit(1);
	}
	
	/* Cabecera del código ASSEMBLER */
	fprintf(pf_asm, "include macros2.asm\n");
	fprintf(pf_asm, "include number.asm\n");
    fprintf(pf_asm, ".MODEL LARGE \n");
    fprintf(pf_asm, ".386 \n");
    fprintf(pf_asm, ".STACK 200h \n");
    fprintf(pf_asm, ".DATA \n");
	
    printf("Generando Cabecera\n");
	for(i=0; i<totalVariables; i++)
    {
	  strcpy(aux_cte, ts_asm[i].nombre); 
      if(!strcmp(ts_asm[i].tipo, "STRING"))
      {
        fprintf(pf_asm, "\t_%s db  %d dup (?) '$'\n", aux_cte, 30 );//30 - Tabla_simb[i].longitud);
      }
      else if(!strcmp(ts_asm[i].tipo, "REAL"))
      {
        fprintf(pf_asm, "\t_%s dd ? \n", aux_cte);
      }
	  else if(!strcmp(ts_asm[i].tipo, "CONST_REAL"))
      {
        fprintf(pf_asm, "\t_%s dd %s \n", aux_cte, aux_cte);
      }
	  else if(!strcmp(ts_asm[i].tipo, "CONST_STRING"))
      {
        fprintf(pf_asm, "\t_%s db %s %d dup (?) \"$\"\n", aux_cte, aux_cte, 30 );//30 - Tabla_simb[i].longitud);
      }
    }
	//variable auxiliar
	fprintf(pf_asm, "\t_aux dd ? \n");
	
    fprintf(pf_asm, ".CODE \n");
    fprintf(pf_asm, "\t mov AX,@DATA \n");
    fprintf(pf_asm, "\t mov DS,AX \n");
    
	/* Código ASSEMBLER */
	printf("Generando CODIGO\n");
	for(i=0;i<indiceTerceto;i++)
	{	
		//printf("terceto de operacion: [%d] %s %d %d\n", vectorTercetos[i].numeroTerceto, vectorTercetos[i].operacion, vectorTercetos[i].t1, vectorTercetos[i].t2);
		//Operadores:Constantes y IDs
		if(vectorTercetos[i].t1 == -1 && vectorTercetos[i].t2 == -1)
		{
			strcpy(operandoresASM[i],vectorTercetos[i].operacion);
		}
		//ASIGNACION
		if (strcmp(vectorTercetos[i].operacion, ":=" ) == 0)
		{
			fprintf(pf_asm, "\t FLD _%s \n", operandoresASM[vectorTercetos[i].t2]);
			fprintf(pf_asm, "\t FSTP _%s  ; Asignacion \n", operandoresASM[vectorTercetos[i].t1]);	
		}
		//OPERACIONES
		if (esOperacion(vectorTercetos[i].operacion) == 0)
		{
			getCodigo(vectorTercetos[i].operacion);
			//printf("es operacion.terceto %d\n",i);
			//Obtengo operadores
			fprintf(pf_asm, "\t FLD _%s \n", operandoresASM[vectorTercetos[i].t1]);
			fprintf(pf_asm, "\t FLD _%s \n", operandoresASM[vectorTercetos[i].t2]);
			//Operacion
			fprintf(pf_asm, "\t %s \n", op_comparacion);
			fprintf(pf_asm, "\t FSTP _aux \n");	
			strcpy(operandoresASM[i],"aux");
		}
	}
	
     
	fprintf(pf_asm, "mov ax, 4C00h \n");
	fprintf(pf_asm, "int 21h \n");
	fprintf(pf_asm, "END \n");
     
    fclose(pf_asm);
}


void getCodigo(char* operador){
	
	//printf("operador: %s\n",operador);
	if (strcmp(operador,"==") == 0) {
		strcpy(op_comparacion,"BNE");
	} else if (strcmp(operador,"><") == 0) {
		strcpy(op_comparacion,"BEQ");
	} else if (strcmp(operador,"<") == 0) {
		strcpy(op_comparacion,"BGE");
	} else if (strcmp(operador,">") == 0) {
		strcpy(op_comparacion,"BLE");
	} else if (strcmp(operador,">=") == 0) {
		strcpy(op_comparacion,"BLT");
	} else if (strcmp(operador,"<=") == 0) {
		strcpy(op_comparacion,"BGT");
	} else if (strcmp(operador,"+") == 0) {
		strcpy(op_comparacion,"FADD");
	}else if (strcmp(operador,"-") == 0) {
		strcpy(op_comparacion,"FSUB");
	}else if (strcmp(operador,"*") == 0) {
		strcpy(op_comparacion,"FMUL");
	}else if (strcmp(operador,"/") == 0) {
		strcpy(op_comparacion,"FDIV");
	}else {
		strcpy(op_comparacion,"NO");
	}
}

int esOperacion(char *operacion){
	if((strcmp(operacion, "*") == 0) 
   ||(strcmp(operacion, "/") == 0) 
   ||(strcmp(operacion, "+") == 0) 
   ||(strcmp(operacion, "-") == 0) 
   ||(strcmp(operacion, "==") == 0) 
   ||(strcmp(operacion, "><") == 0) 
   ||(strcmp(operacion, "<") == 0) 
   ||(strcmp(operacion, ">") == 0) 
   ||(strcmp(operacion, ">=") == 0) 
   ||(strcmp(operacion, "<=") == 0))
	   return 0;

	 return 1;
}
int obtenerTablaSimbolosCompleta()
{
	FILE* pf_tabla_simb;
	char linea[500];
	char tab[2] = "\t";
	char* campo;
	char* cadena;
	
	TS_reg reg;
	
	if((pf_tabla_simb = fopen("ts.txt", "r")) == NULL ){
		printf("No se pudo abrir archivo ts.txt");
		return 1;
	}
	//La primer linea la salteo
	fgets(linea,sizeof(linea),pf_tabla_simb);
	
	while(fgets(linea,sizeof(linea),pf_tabla_simb))
	{
		//printf ("linea: %s", linea);
		campo = strtok(linea,tab);
		if(!campo)
			return 1;
		sscanf(campo,"\t%d",&reg.posicion);
		
		campo = strtok(NULL,tab);
		if(!campo)
			return 1;
		if(strlen(campo)>30)
			campo[30]= '\0';
		strcpy(reg.nombre,campo);
		
		campo = strtok(NULL,tab);
		if(!campo)
			return 1;
		if(strlen(campo)>20)
			campo[20]= '\0';
		strcpy(reg.tipo,campo);
				
		campo = strtok(NULL,tab);
		if(!campo)
			return 1;
		if(strlen(campo)>100)
			campo[100]= '\0';
		strcpy(reg.nombre,campo);
			
		campo = strtok(NULL,tab);
		if(!campo)
			return 1;
		sscanf(campo,"\t%d",&reg.longitud);
				
		ts_asm[totalVariables++] = reg;
		
	}
	return 0;
}

char* buscaTipoEnTS(char* nombre)
{
    int i;
    for(i = 0; i<totalVariables; i++)
    {
          if(!strcmp(ts_asm[i].nombre, nombre))
          {
                 return ts_asm[i].tipo;
          }
    }
    
    return NULL;
}

//PRIMITIVAS PILA
/** inserta un entero en la pila */
void insertar_pila (t_pila *p, int valor) {
	printf("inicio insertar pila\n");
    // creo nodo
    t_nodo *nodo = (t_nodo*) malloc (sizeof(t_nodo));
	printf("1\n");
    // asigno valor
    nodo->valor = valor;
	printf("2\n");
    // apunto al elemento siguiente
    nodo->sig = *p;
	printf("3\n");
    // apunto al tope de la pila
    *p = nodo;
	printf("fin insertar pila\n");
}

/** obtiene un entero de la pila */
int sacar_pila(t_pila *p) {
    int valor = -1;
    t_nodo *aux;
    if (*p != NULL) {
       aux = *p;
       valor = aux->valor;
       *p = aux->sig;
       free(aux);
    }
    return valor;
}

/** crea una estructura de pila */
void crear_pila(t_pila *p) {
    *p = NULL;
}

/** destruye pila */
void destruir_pila(t_pila *p) {
    while ( -1 != sacar_pila(p));
}
