/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilator.y"

    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    extern FILE* yyin;
    extern char* yytext;
    extern int yylineno;
    int fd, fd1;
    char buff[100];
   
    struct node
    {
        char tip[100];
        char id[100];
        int intval;
        char charval[100];
        float floatval;
        struct node *next;
    };

    struct node *head_variable=NULL;
    struct node *current_variable=NULL;
    struct node *head_function=NULL;
    struct node *current_function=NULL;

    int findV(char id[])
    {
        struct node *current_variable=head_variable;

        if(head_variable==NULL)  //nu avem nicio variabila inregistrata
            return 0; 
        
        while(strcmp(current_variable->id,id)!=0) //denumirile difera
        {
            if(current_variable->next==NULL) //nu avem nicio variabila inregistrata
                return 0;
            else 
                current_variable=current_variable->next;
        }

        return 1;   //daca ajungem aici, inseamna ca am gasit deja o variabila cu acelasi id
    }

    void insert_variable(char tip[],char id[],int intval,char charval[],float floatval)
    {
        if(findV(id)==1) //exista deja variabila cu acest nume
        {
            printf("(LINE %d) Sunt doua variabile cu acelasi nume: %s\n",yylineno,id);
            exit(1);
        }

        //daca ajungem aici, inseamna ca nu avem deja acest nume in program
        struct node *new=(struct node*)malloc(sizeof(struct node));
        strcpy(new->tip,tip);
        strcpy(new->id,id);
        new->intval=intval;
        strcpy(new->charval,charval);
        new->floatval=floatval;
        
        //adaugare variabila la final de lista
        if(head_variable==NULL)
            head_variable=new;
        else
        {
            struct node *current_variable=head_variable;
            while(current_variable->next !=NULL)
                current_variable=current_variable->next;
            current_variable->next=new;
        }
    }

    int findF(char id[])
    {
        struct node *current_function=head_function;

        if(head_function==NULL)  //nu avem nicio functie inregistrata
            return 0; 
        
        while(strcmp(current_function->id,id)!=0) //denumirile difera
        {
            if(current_function->next==NULL) //nu avem nicio variabila inregistrata
                return 0;
            else 
                current_function=current_function->next;
        }

        return 1;   //daca ajungem aici, inseamna ca am gasit deja o variabila cu acelasi id
    }

    void insertFunction(char tip[],char id[],int intval,char charval[],float floatval)
    {
        if(findF(id)==1) //exista deja functie cu acest nume
        {
            printf("(LINE %d) Sunt doua functii cu acelasi nume: %s\n",yylineno,id);
            exit(1);
        }

        //daca ajungem aici, inseamna ca nu avem deja acest nume in program
        struct node *new=(struct node*)malloc(sizeof(struct node));
        strcpy(new->tip,tip);
        strcpy(new->id,id);
        new->intval=intval;
        strcpy(new->charval,charval);
        new->floatval=floatval;

        //adaugare functie la final de lista
        if(head_function==NULL)
            head_function=new;
        else
        {
            struct node *current_function=head_function;
            while(current_function->next !=NULL)
                current_function=current_function->next;
            current_function->next=new;
        }
    }

    
   

#line 194 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TIP = 258,
    BEGINP = 259,
    ENDP = 260,
    VOID = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    CLASS = 266,
    CLASS_TIP = 267,
    BOOL_VARIABLE = 268,
    ID = 269,
    CONST_STRING = 270,
    CHAR = 271,
    ARRAY = 272,
    CONST_FLOAT = 273,
    CONST_INT = 274,
    LB = 275,
    RB = 276,
    PLUS = 277,
    MINUS = 278,
    MUL = 279,
    DIV = 280,
    LESS = 281,
    GREAT = 282,
    LESSEQ = 283,
    GREATEQ = 284,
    EQ = 285,
    AND = 286,
    OR = 287,
    PRINT = 288,
    TYPEOF = 289,
    EVAL = 290
  };
#endif
/* Tokens.  */
#define TIP 258
#define BEGINP 259
#define ENDP 260
#define VOID 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define CLASS 266
#define CLASS_TIP 267
#define BOOL_VARIABLE 268
#define ID 269
#define CONST_STRING 270
#define CHAR 271
#define ARRAY 272
#define CONST_FLOAT 273
#define CONST_INT 274
#define LB 275
#define RB 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define LESS 281
#define GREAT 282
#define LESSEQ 283
#define GREATEQ 284
#define EQ 285
#define AND 286
#define OR 287
#define PRINT 288
#define TYPEOF 289
#define EVAL 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 126 "compilator.y"

     int intv;
     char* strv;
     float floatval;

#line 322 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,    38,    36,    42,    37,    45,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   160,   160,   163,   164,   167,   168,   169,   179,   189,
     198,   207,   207,   210,   210,   211,   214,   215,   216,   217,
     220,   221,   224,   225,   226,   227,   230,   231,   234,   235,
     238,   239,   242,   245,   246,   249,   250,   251,   254,   257,
     258,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   270,   276,   277,   278,   279,   280,   283,   284,   287,
     293,   299,   300,   303,   304,   307,   308,   311,   312,   313,
     314,   317,   318,   319,   320,   321,   322,   323,   326,   327,
     328,   329,   332,   333,   334,   335,   338,   339
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TIP", "BEGINP", "ENDP", "VOID", "IF",
  "ELSE", "WHILE", "FOR", "CLASS", "CLASS_TIP", "BOOL_VARIABLE", "ID",
  "CONST_STRING", "CHAR", "ARRAY", "CONST_FLOAT", "CONST_INT", "LB", "RB",
  "PLUS", "MINUS", "MUL", "DIV", "LESS", "GREAT", "LESSEQ", "GREATEQ",
  "EQ", "AND", "OR", "PRINT", "TYPEOF", "EVAL", "'+'", "'-'", "'*'", "'/'",
  "';'", "'='", "','", "'('", "')'", "'.'", "$accept", "s",
  "declaratiiTip", "declaratieTip", "$@1", "vars", "$@2", "var",
  "declaratieFunctii", "declaratieFunctie", "params", "param",
  "declaratieClase", "declaratieClasa", "class_elems", "class_elem",
  "program", "bloc", "instr", "$@3", "apel_clasa", "arg", "apel_functie",
  "params2", "expresie_bool", "operator_bool", "expresie_math",
  "operator_math", "op_for", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    43,    45,    42,    47,
      59,    61,    44,    40,    41,    46
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      51,     8,    63,    81,    61,    23,    71,    97,   -72,    79,
      85,    83,    91,   -72,   -72,    95,   -72,    86,    90,   -72,
     125,   126,   -72,   138,   132,   -72,   -72,   -72,   -72,   124,
       0,     1,   102,   127,     6,   -72,   -72,    82,   134,   135,
     130,    92,   -72,   131,    93,   140,   112,   113,   114,    87,
     115,   116,   120,   141,     6,   121,   122,   -72,   -72,   -72,
     -72,     9,   -72,   -72,   -72,     6,    52,   143,     6,   144,
      46,    58,   128,    -4,    -4,   162,    10,    -2,   152,    13,
      13,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   146,   -72,
       6,   148,     6,   156,    51,   -72,   133,   -72,    77,    -4,
     136,   137,   157,    35,   139,   142,   145,   147,     5,   149,
     150,   -72,   151,   129,   -72,    60,   -72,   -72,     7,   153,
     -72,   -72,   154,    82,   -72,   155,   -72,   163,   -72,    59,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   103,   158,
     166,   168,   159,   -72,   -72,   -72,   -72,   -72,   106,   -72,
     -72,   -72,   -72,    49,   160,   -72,   161,   -72,   165,   167,
     -72,   -72,   -72,   -72,    40,   -72,   -72,   -72,    77,     6,
       6,   164,   -72,   -72,   -72,    49,   -72,   -72,   -72,   -72,
     169,   170,   172,   -72,   171,    -4,   182,   -72,   173,     5,
     174,   176,    -4,   175,   -72,     6,   177,   -72,   178,   180,
     -72,    12,   179,   181,   183,   188,   -72,   -72,     6,   189,
     -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     5,     6,     1,     0,
       0,     0,     0,    21,     4,     0,    11,     5,     0,     3,
       0,     0,    20,     0,    31,     8,    10,     9,     7,     0,
       0,     0,     0,     0,     0,     2,    30,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    19,    18,    17,
      16,     0,    15,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    38,    40,    56,    55,    12,    13,     0,    26,
       0,     0,     0,     0,     0,    32,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,    64,     0,    57,    58,     0,    60,    59,     0,     0,
      62,    61,     0,     0,    23,     0,    25,     0,    35,     0,
      34,    71,    73,    72,    74,    75,    76,    77,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    45,     0,    43,
      44,    42,    41,     0,     0,    46,     0,    63,     0,     0,
      14,    22,    24,    37,     0,    67,    69,    68,     0,     0,
       0,     0,    78,    80,    79,     0,    65,    53,    52,    36,
       0,     0,     0,    50,     0,     0,    47,    49,     0,     0,
       0,     0,     0,     0,    70,     0,     0,    81,     0,     0,
      48,     0,     0,     0,     0,     0,    86,    87,     0,     0,
      51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,    80,     2,   -72,   -72,   -72,    54,    72,   -11,
     184,   185,   187,   -72,   -72,   107,   -72,   -54,   -72,   -72,
     -72,   186,   190,    53,   -66,    48,   -71,    45,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    52,    29,    61,   123,    62,    12,    13,
      41,    42,    23,    24,    71,    72,    35,    53,    54,   188,
      55,   119,    56,   112,   120,   138,   121,   148,   202
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      83,    22,     5,    38,    38,   109,    11,   100,   101,     1,
      98,    88,   110,    46,    91,    47,    48,    39,    39,   153,
      49,   115,     6,     2,   103,   104,   105,   115,   106,   107,
      86,   116,   117,   139,   203,   204,   125,   154,   127,    99,
      50,    51,   111,    20,    40,    43,    10,   154,   108,    93,
     118,    87,   139,   108,     1,    38,   118,   143,   144,   145,
     146,   179,     9,    14,     9,    10,    94,    10,     2,    39,
      70,   143,   144,   145,   146,   147,     2,     7,     2,    95,
     163,     8,   143,   144,   145,   146,   131,   132,   133,   134,
     135,   136,   137,    17,    20,    57,     5,    10,    58,    18,
      59,    60,    21,   131,   132,   133,   134,   135,   136,   137,
      25,    26,    15,    27,    28,   181,   182,   165,   193,   190,
     172,   166,   167,    19,   173,   174,   196,    15,    76,    30,
      77,    11,    78,    31,    66,    66,    67,    69,    16,    32,
      33,   198,    34,    21,    37,    30,    82,    45,    63,    64,
      65,    68,    70,    22,   209,    73,    74,    75,    79,    80,
      81,    84,    85,    90,    92,   102,   113,   124,    97,   126,
     128,   142,    77,   130,   129,   110,   161,   160,    96,   149,
     140,   141,   150,   183,   162,   151,   169,   152,   170,   155,
     191,   186,   156,   187,   201,   157,   195,   158,   159,   200,
     171,   164,   168,   206,   175,   177,   207,   178,   208,   176,
     210,    36,   185,   192,   189,    44,   180,   199,   194,   197,
     184,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   122,     0,   114
};

static const yytype_int16 yycheck[] =
{
      54,    12,     0,     3,     3,    76,     4,    73,    74,     3,
      14,    65,    14,     7,    68,     9,    10,    17,    17,    14,
      14,    14,    14,    17,    14,    15,    16,    14,    18,    19,
      21,    18,    19,    99,    22,    23,    90,   108,    92,    43,
      34,    35,    44,     3,    44,    44,     6,   118,    43,     3,
      43,    42,   118,    43,     3,     3,    43,    22,    23,    24,
      25,    21,     3,    40,     3,     6,    20,     6,    17,    17,
      12,    22,    23,    24,    25,    40,    17,    14,    17,    21,
      21,     0,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    14,     3,    13,    94,     6,    16,    14,
      18,    19,    11,    26,    27,    28,    29,    30,    31,    32,
      15,    16,    41,    18,    19,   169,   170,    14,   189,   185,
      14,    18,    19,    40,    18,    19,   192,    41,    41,    43,
      43,   129,    45,    43,    42,    42,    44,    44,    41,    14,
      14,   195,     4,    11,    20,    43,     5,    20,    14,    14,
      20,    20,    12,   164,   208,    43,    43,    43,    43,    43,
      40,    40,    40,    20,    20,     3,    14,    21,    40,    21,
      14,    14,    43,    40,    94,    14,    21,   123,    71,    40,
      44,    44,    40,    19,    21,    40,    20,    40,    20,    40,
       8,    21,    42,    21,    14,    44,    20,    44,    44,    21,
      41,   129,    44,    22,    44,    40,    23,    40,    20,   156,
      21,    24,    43,    40,    43,    31,   168,    40,    44,    44,
     175,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    17,    47,    48,    49,    14,    14,     0,     3,
       6,    49,    54,    55,    40,    41,    41,    14,    14,    40,
       3,    11,    55,    58,    59,    15,    16,    18,    19,    50,
      43,    43,    14,    14,     4,    62,    58,    20,     3,    17,
      44,    56,    57,    44,    56,    20,     7,     9,    10,    14,
      34,    35,    49,    63,    64,    66,    68,    13,    16,    18,
      19,    51,    53,    14,    14,    20,    42,    44,    20,    44,
      12,    60,    61,    43,    43,    43,    41,    43,    45,    43,
      43,    40,     5,    63,    40,    40,    21,    42,    63,    57,
      20,    63,    20,     3,    20,    21,    61,    40,    14,    43,
      70,    70,     3,    14,    15,    16,    18,    19,    43,    72,
      14,    44,    69,    14,    68,    14,    18,    19,    43,    67,
      70,    72,    67,    52,    21,    63,    21,    63,    14,    48,
      40,    26,    27,    28,    29,    30,    31,    32,    71,    70,
      44,    44,    14,    22,    23,    24,    25,    40,    73,    40,
      40,    40,    40,    14,    72,    40,    42,    44,    44,    44,
      53,    21,    21,    21,    54,    14,    18,    19,    44,    20,
      20,    41,    14,    18,    19,    44,    69,    40,    40,    21,
      71,    63,    63,    19,    73,    43,    21,    21,    65,    43,
      70,     8,    40,    72,    44,    20,    70,    44,    63,    40,
      21,    14,    74,    22,    23,    44,    22,    23,    20,    63,
      21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    49,    52,    51,    51,    53,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    61,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    64,    64,    64,    64,    64,    64,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     2,     2,     4,     4,     4,
       4,     0,     7,     0,     4,     1,     1,     1,     1,     1,
       2,     1,     8,     7,     8,     7,     3,     1,     2,     2,
       2,     1,     5,     2,     3,     3,     5,     4,     3,     1,
       2,     4,     4,     4,     4,     4,     4,     7,    11,     7,
       0,    15,     5,     5,     2,     2,     2,     3,     3,     1,
       1,     1,     1,     4,     3,     3,     1,     3,     3,     3,
       7,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     7,     1,     1,     1,     1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 160 "compilator.y"
                                                            {printf("program corect sintactic\n");}
#line 1645 "y.tab.c"
    break;

  case 5:
#line 167 "compilator.y"
                       { snprintf(buff,100,"(%s) %s \n",(yyvsp[-1].strv), (yyvsp[0].strv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-1].strv),(yyvsp[0].strv),0,"",0);}
#line 1651 "y.tab.c"
    break;

  case 6:
#line 168 "compilator.y"
                         { snprintf(buff,100,"(%s) %s\n",(yyvsp[-1].strv), (yyvsp[0].strv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-1].strv),(yyvsp[0].strv),0,"",0);}
#line 1657 "y.tab.c"
    break;

  case 7:
#line 170 "compilator.y"
                    { 
                        if(strstr((yyvsp[-3].strv),"int")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        else
                            snprintf(buff,100,"(%s) %s = %d\n",(yyvsp[-3].strv), (yyvsp[-2].strv),(yyvsp[0].intv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-3].strv),(yyvsp[-2].strv),(yyvsp[0].intv),"",0);
                    }
#line 1671 "y.tab.c"
    break;

  case 8:
#line 180 "compilator.y"
                    { 
                        if(strstr((yyvsp[-3].strv),"char")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        else
                            snprintf(buff,100,"(%s) %s = %s\n",(yyvsp[-3].strv),(yyvsp[-2].strv),(yyvsp[0].strv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-3].strv),(yyvsp[-2].strv),0,(yyvsp[0].strv),0);
                    }
#line 1685 "y.tab.c"
    break;

  case 9:
#line 190 "compilator.y"
                    { 
                        if(strstr((yyvsp[-3].strv),"float")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        snprintf(buff,100,"(%s) %s = %f\n",(yyvsp[-3].strv),(yyvsp[-2].strv),(yyvsp[0].floatval)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-3].strv),(yyvsp[-2].strv),0,"",(yyvsp[0].floatval));
                    }
#line 1698 "y.tab.c"
    break;

  case 10:
#line 199 "compilator.y"
                    { 
                        if(strstr((yyvsp[-3].strv),"char")==NULL)
                        {
                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                            exit(1);
                        }
                        snprintf(buff,100,"(%s) %s = %s\n",(yyvsp[-3].strv),(yyvsp[-2].strv),(yyvsp[0].strv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-3].strv),(yyvsp[-2].strv),0,(yyvsp[0].strv),0);
                    }
#line 1711 "y.tab.c"
    break;

  case 11:
#line 207 "compilator.y"
                             { snprintf(buff,100,"(%s) %s = {",(yyvsp[-2].strv),(yyvsp[-1].strv)); write(fd, buff, strlen(buff));insert_variable((yyvsp[-2].strv),(yyvsp[-1].strv),0,"",0);}
#line 1717 "y.tab.c"
    break;

  case 12:
#line 207 "compilator.y"
                                                                                                                                               {write(fd," }\n",3);}
#line 1723 "y.tab.c"
    break;

  case 13:
#line 210 "compilator.y"
                {write(fd,",",1);}
#line 1729 "y.tab.c"
    break;

  case 16:
#line 214 "compilator.y"
                {snprintf(buff,100," %d",(yyvsp[0].intv));write(fd,buff,strlen(buff));}
#line 1735 "y.tab.c"
    break;

  case 17:
#line 215 "compilator.y"
                  {snprintf(buff,100," %f",(yyvsp[0].floatval));write(fd,buff,strlen(buff));}
#line 1741 "y.tab.c"
    break;

  case 18:
#line 216 "compilator.y"
           {snprintf(buff,100," %s",(yyvsp[0].strv));write(fd,buff,strlen(buff));}
#line 1747 "y.tab.c"
    break;

  case 19:
#line 217 "compilator.y"
                    {snprintf(buff,100," %s",(yyvsp[0].strv));write(fd,buff,strlen(buff));}
#line 1753 "y.tab.c"
    break;

  case 22:
#line 224 "compilator.y"
                                                     { snprintf(buff,100,"(%s) %s (%s) \n",(yyvsp[-7].strv), (yyvsp[-6].strv),(yyvsp[-4].strv)); write(fd1, buff, strlen(buff));insertFunction((yyvsp[-7].strv),(yyvsp[-6].strv),0,"",0);}
#line 1759 "y.tab.c"
    break;

  case 23:
#line 225 "compilator.y"
                                              { snprintf(buff,100,"(%s) %s\n",(yyvsp[-6].strv), (yyvsp[-5].strv)); write(fd1, buff, strlen(buff));insertFunction((yyvsp[-6].strv),(yyvsp[-5].strv),0,"",0);}
#line 1765 "y.tab.c"
    break;

  case 24:
#line 226 "compilator.y"
                                                      { snprintf(buff,100,"(%s) %s (%s)\n",(yyvsp[-7].strv), (yyvsp[-6].strv),(yyvsp[-4].strv)); write(fd1, buff, strlen(buff));insertFunction((yyvsp[-7].strv),(yyvsp[-6].strv),0,"",0);}
#line 1771 "y.tab.c"
    break;

  case 25:
#line 227 "compilator.y"
                                               { snprintf(buff,100,"(%s) %s\n",(yyvsp[-6].strv), (yyvsp[-5].strv)); write(fd1, buff, strlen(buff));insertFunction((yyvsp[-6].strv),(yyvsp[-5].strv),0,"",0);}
#line 1777 "y.tab.c"
    break;

  case 26:
#line 230 "compilator.y"
                          {strcat((yyvsp[-2].strv),", ");strcat((yyvsp[-2].strv),(yyvsp[0].strv)); (yyval.strv)=(yyvsp[-2].strv);}
#line 1783 "y.tab.c"
    break;

  case 27:
#line 231 "compilator.y"
               {(yyval.strv)=(yyvsp[0].strv);}
#line 1789 "y.tab.c"
    break;

  case 28:
#line 234 "compilator.y"
               {snprintf(buff,100,"(%s) %s ",(yyvsp[-1].strv), (yyvsp[0].strv)); strcpy((yyval.strv),buff);}
#line 1795 "y.tab.c"
    break;

  case 29:
#line 235 "compilator.y"
                 { snprintf(buff,100,"(%s) %s ",(yyvsp[-1].strv), (yyvsp[0].strv));strcpy((yyval.strv),buff);}
#line 1801 "y.tab.c"
    break;

  case 50:
#line 270 "compilator.y"
                                    { if(strstr((yyvsp[-3].strv),"int")==NULL)
                                        {
                                            printf("(LINE %d) Variabila este de alt tip!",yylineno);
                                            exit(1);
                                        }
                                    }
#line 1812 "y.tab.c"
    break;

  case 52:
#line 276 "compilator.y"
                             {snprintf(buff,100,"%s (%s) \n", "Eval" ,(yyvsp[-2].strv)); write(fd1, buff, strlen(buff));}
#line 1818 "y.tab.c"
    break;

  case 59:
#line 288 "compilator.y"
        {
            char conversion[100];
            sprintf(conversion,"%d",(yyvsp[0].intv));
            (yyval.strv)=conversion;
        }
#line 1828 "y.tab.c"
    break;

  case 60:
#line 294 "compilator.y"
        {
            char conversion[100];
            sprintf(conversion,"%f",(yyvsp[0].floatval));
            (yyval.strv)=conversion;
        }
#line 1838 "y.tab.c"
    break;


#line 1842 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 342 "compilator.y"


void yyerror(char *s)
{
    printf("eroare: %s la linia: %d\n",s,yylineno);
}
int main(int argc,char** argv)
{
    fd = open ("symbol_table.txt", O_RDWR|O_TRUNC|O_CREAT);
    fd1 = open ("symbol_table_functions.txt", O_RDWR|O_TRUNC|O_CREAT);
    yyin=fopen(argv[1],"r");
    yyparse();
}
