/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    CHAR = 259,                    /* CHAR  */
    FLOAT = 260,                   /* FLOAT  */
    DOUBLE = 261,                  /* DOUBLE  */
    WHILE = 262,                   /* WHILE  */
    FOR = 263,                     /* FOR  */
    DO = 264,                      /* DO  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    SWITCH = 267,                  /* SWITCH  */
    CASE = 268,                    /* CASE  */
    BREAK = 269,                   /* BREAK  */
    CONTINUE = 270,                /* CONTINUE  */
    RETURN = 271,                  /* RETURN  */
    ID = 272,                      /* ID  */
    NUM = 273,                     /* NUM  */
    STRLITERAL = 274,              /* STRLITERAL  */
    HEADER = 275,                  /* HEADER  */
    EQCOMP = 276,                  /* EQCOMP  */
    GREATEREQ = 277,               /* GREATEREQ  */
    LESSEREQ = 278,                /* LESSEREQ  */
    NOTEQ = 279,                   /* NOTEQ  */
    INC = 280,                     /* INC  */
    DEC = 281,                     /* DEC  */
    OROR = 282,                    /* OROR  */
    ANDAND = 283,                  /* ANDAND  */
    BREAK_T = 284,                 /* BREAK_T  */
    CONTINUE_T = 285,              /* CONTINUE_T  */
    RETURN_T = 286,                /* RETURN_T  */
    IF_T = 287,                    /* IF_T  */
    ELSE_T = 288,                  /* ELSE_T  */
    WHILE_T = 289,                 /* WHILE_T  */
    DO_T = 290,                    /* DO_T  */
    FOR_T = 291,                   /* FOR_T  */
    SWITCH_T = 292,                /* SWITCH_T  */
    CASE_T = 293                   /* CASE_T  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define CHAR 259
#define FLOAT 260
#define DOUBLE 261
#define WHILE 262
#define FOR 263
#define DO 264
#define IF 265
#define ELSE 266
#define SWITCH 267
#define CASE 268
#define BREAK 269
#define CONTINUE 270
#define RETURN 271
#define ID 272
#define NUM 273
#define STRLITERAL 274
#define HEADER 275
#define EQCOMP 276
#define GREATEREQ 277
#define LESSEREQ 278
#define NOTEQ 279
#define INC 280
#define DEC 281
#define OROR 282
#define ANDAND 283
#define BREAK_T 284
#define CONTINUE_T 285
#define RETURN_T 286
#define IF_T 287
#define ELSE_T 288
#define WHILE_T 289
#define DO_T 290
#define FOR_T 291
#define SWITCH_T 292
#define CASE_T 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
