/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
