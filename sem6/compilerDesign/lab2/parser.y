%{
#include <stdio.h>
#include <stdlib.h>
#include "sym_tab.h"

/* These come from Flex. */
extern int yylex();
extern int line_number;
extern int current_scope;

/* Bison error handler */
void yyerror(const char *s);
%}

/* The global union for token/AST node values */
%union {
    int    int_val;
    float  float_val;
    char*  string_val;
}

/* Tokens that carry values must specify which part of %union they use */
%token <string_val> IDENTIFIER
%token <int_val>    INTEGER_LITERAL
%token <float_val>  FLOAT_LITERAL
%token <string_val> CHAR_LITERAL

%token INT FLOAT DOUBLE CHAR VOID

/* This line is critical for Bison to know that the 'type' nonterminal
   will use the 'int_val' field of %union. */
%type <int_val> type

%%

program:
    /* empty */
  | program function
  ;

function:
    type IDENTIFIER '(' ')' compound_stmt
    {
       /* is_function = 1 */
       insert_symbol($2, $1, line_number, /*scope=*/0, /*is_function=*/1);
       free($2);
    }
  ;

compound_stmt:
    '{' stmt_list '}'
  ;

stmt_list:
    /* empty */
  | stmt_list declaration
  ;

declaration:
    type IDENTIFIER ';'
    {
       /* is_function = 0 */
       insert_symbol($2, $1, line_number, current_scope, 0);
       free($2);
    }
  ;

type:
    CHAR    { $$ = 1; }
  | INT     { $$ = 2; }
  | FLOAT   { $$ = 3; }
  | DOUBLE  { $$ = 4; }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", line_number, s);
}

int main() {
    init_symbol_table();
    yyparse();
    display_symbol_table();
    free_symbol_table();
    return 0;
}
