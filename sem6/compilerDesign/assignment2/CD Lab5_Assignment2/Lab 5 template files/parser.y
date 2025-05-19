%{
	#include "quad_generation.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define YYSTYPE char*

	void yyerror(char* s);
	int yylex();
	extern int yylineno;

	FILE* icg_quad_file;
	int temp_no = 1;
%}

%token T_ID T_NUM T_IF T_ELSE T_DO T_WHILE

%start START

%%

START : STATEMENT { 
					printf("Valid syntax\n");
					YYACCEPT;
				}
      ;

STATEMENT : ASSGN
          | IF_ELSE
          | DO_WHILE
          ;

/* Assignment */
ASSGN : T_ID '=' E ';' {
		printf("Assignment statement detected\n");
	}
    ;

/* If-Else Statement */
IF_ELSE : T_IF '(' E ')' '{' STATEMENT '}' T_ELSE '{' STATEMENT '}' {
			printf("If-Else statement detected\n");
		}
        ;

/* Do-While Statement */
DO_WHILE : T_DO '{' STATEMENT '}' T_WHILE '(' E ')' ';' {
			printf("Do-While statement detected\n");
		}
        ;

/* Expressions */
E : E '+' T  { printf("Addition detected\n"); }
  | E '-' T  { printf("Subtraction detected\n"); }
  | T
  ;

T : T '*' F  { printf("Multiplication detected\n"); }
  | T '/' F  { printf("Division detected\n"); }
  | F
  ;

F : '(' E ')'  
  | T_ID       
  | T_NUM
  ;

%%

void yyerror(char* s) {
	printf("Error : %s at line %d\n", s, yylineno);
}

int main(int argc, char* argv[]) {
	icg_quad_file = fopen("icg_quad.txt", "w");

	yyparse();
	fclose(icg_quad_file);
	return 0;
}
