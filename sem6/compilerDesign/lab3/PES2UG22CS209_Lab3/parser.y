%{
    /* Remove the inclusion of sym_tab.c here to avoid multiple definitions */
    #include "sym_tab.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(char* s);
    int yylex();
    extern int yylineno;
    extern int current_scope;   /* Defined in lexer.l */
    
    /* Global variable to store the type of a declaration:
       2 for int, 3 for float/double, 1 for char */
    int current_type = 0;
%}

/* Define a union for semantic values */
%union {
    char* str;
}

/* Declare tokens. Note that T_ID, T_NUM, and T_STRLITERAL use the union’s 'str' field. */
%token T_INT T_CHAR T_DOUBLE T_WHILE T_INC T_DEC T_OROR T_ANDAND T_EQCOMP T_NOTEQUAL 
%token T_GREATEREQ T_LESSEREQ T_LEFTSHIFT T_RIGHTSHIFT T_PRINTLN T_STRING T_FLOAT T_BOOLEAN 
%token T_IF T_ELSE T_DO T_INCLUDE T_HEADER T_MAIN
%token <str> T_ID T_NUM T_STRLITERAL

/* Declare nonterminals that carry a string value */
%type <str> START PROG DECLR LISTVAR VAR TYPE ASSGN EXPR E T F REL_OP MAIN EMPTY_LISTVAR STMT STMT_NO_BLOCK BLOCK COND

%start START

%%

START 
    : PROG { 
            printf("Valid syntax\n"); 
            YYACCEPT;
          }
    ;

PROG 
    : MAIN PROG
    | DECLR ';' PROG
    | ASSGN ';' PROG
    | /* empty */
    ;

DECLR 
    : TYPE LISTVAR
    ;

LISTVAR 
    : LISTVAR ',' VAR
    | VAR
    ;

VAR
    : T_ID '=' EXPR {
                if (lookup_symbol($1, current_scope) != NULL) {
                    printf("Variable %s already declared\n", $1);
                    yyerror($1);
                } else {
                    double val = atof($3);
                    insert_symbol($1, current_type, yylineno, current_scope, 0, val);
                }
                $$ = $1;
            }
    | T_ID {
                if (lookup_symbol($1, current_scope) != NULL) {
                    printf("Variable %s already declared\n", $1);
                    yyerror($1);
                } else {
                    insert_symbol($1, current_type, yylineno, current_scope, 0, 0.0);
                }
                $$ = $1;
            }
    ;

TYPE 
    : T_INT    { current_type = 2; $$ = "int"; }
    | T_FLOAT  { current_type = 3; $$ = "float"; }
    | T_DOUBLE { current_type = 3; $$ = "double"; }
    | T_CHAR   { current_type = 1; $$ = "char"; }
    ;

ASSGN 
    : T_ID '=' EXPR {
                Symbol* sym = lookup_symbol($1, current_scope);
                if (sym == NULL) {
                    printf("Error: %s not declared\n", $1);
                    yyerror($1);
                } else {
                    double val = atof($3);
                    update_symbol($1, val);
                }
                $$ = $1;
            }
    ;

EXPR 
    : EXPR REL_OP E { $$ = $1; }
    | E { $$ = $1; }
    ;

E 
    : E '+' T {
                    double l = atof($1);
                    double r = atof($3);
                    double res = l + r;
                    char buf[64];
                    sprintf(buf, "%lf", res);
                    $$ = strdup(buf);
              }
    | E '-' T {
                    double l = atof($1);
                    double r = atof($3);
                    double res = l - r;
                    char buf[64];
                    sprintf(buf, "%lf", res);
                    $$ = strdup(buf);
              }
    | T { $$ = $1; }
    ;

T 
    : T '*' F {
                    double l = atof($1);
                    double r = atof($3);
                    double res = l * r;
                    char buf[64];
                    sprintf(buf, "%lf", res);
                    $$ = strdup(buf);
              }
    | T '/' F {
                    double l = atof($1);
                    double r = atof($3);
                    if(r == 0) {
                        yyerror("Division by zero");
                        $$ = strdup("0");
                    } else {
                        double res = l / r;
                        char buf[64];
                        sprintf(buf, "%lf", res);
                        $$ = strdup(buf);
                    }
              }
    | F { $$ = $1; }
    ;

F 
    : '(' EXPR ')' { $$ = $2; }
    | T_ID {
                    Symbol* sym = lookup_symbol($1, current_scope);
                    if(sym == NULL) {
                        printf("Error :%s at %d\n", $1, yylineno);
                        yyerror($1);
                        $$ = strdup("0");
                    } else {
                        char buf[64];
                        sprintf(buf, "%lf", sym->value);
                        $$ = strdup(buf);
                    }
              }
    | T_NUM { $$ = $1; }
    | T_STRLITERAL { $$ = $1; }
    ;

REL_OP 
    : T_LESSEREQ
    | T_GREATEREQ
    | '<'
    | '>'
    | T_EQCOMP
    | T_NOTEQUAL
    ;

MAIN 
    : TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' STMT '}' 
    ;

EMPTY_LISTVAR 
    : LISTVAR
    | /* empty */
    ;

STMT 
    : STMT_NO_BLOCK STMT
    | BLOCK STMT
    | /* empty */
    ;

STMT_NO_BLOCK 
    : DECLR ';'
    | ASSGN ';'
    ;

BLOCK 
    : '{' STMT '}' 
    ;

COND 
    : EXPR
    | ASSGN
    ;

%%

void yyerror(char* s) {
    printf("Error :%s at %d\n", s, yylineno);
}

int main(int argc, char* argv[]) {
    init_symbol_table();
    yyparse();
    display_symbol_table();
    return 0;
}
