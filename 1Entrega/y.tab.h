
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

