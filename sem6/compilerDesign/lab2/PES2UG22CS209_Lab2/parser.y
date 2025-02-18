%{
#include <stdio.h>
#include <stdlib.h>
#include "sym_tab.h"

extern int line_number;
extern int current_scope;
extern int yylex();

void yyerror(const char *s);
%}

%union {
    int    int_val;
    float  float_val;
    char*  string_val;
}

%token <string_val> IDENTIFIER
%token <int_val> INTEGER_LITERAL
%token <float_val> FLOAT_LITERAL
%token <string_val> CHAR_LITERAL
%token INT FLOAT DOUBLE CHAR VOID

%type <int_val> type
%%
program:
    /* empty */
    | program function
    ;

function:
    type IDENTIFIER '(' ')' compound_stmt
    {
        insert_symbol($2, $<int_val>1, line_number, 0, 1); // is_function = 1
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
        insert_symbol($2, $<int_val>1, line_number, current_scope, 0); // is_function = 0
        free($2);
    }
    ;

type:
    CHAR   { $$ = 1; }
    | INT    { $$ = 2; }
    | FLOAT  { $$ = 3; }
    | DOUBLE { $$ = 4; }
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
