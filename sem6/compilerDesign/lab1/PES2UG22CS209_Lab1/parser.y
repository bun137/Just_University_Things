%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int line_number;
extern char *yytext;
void yyerror(const char *s);
void suppress_redundant_errors(const char *error_message);
int err = 0;
int last_error_line = -1;
%}

%token INT FLOAT CHAR DOUBLE RETURN BREAK CONTINUE IF ELSE FOR WHILE DO SWITCH CASE DEFAULT MAIN
%token ID NUM FLOAT_LITERAL CHAR_LITERAL RELOP ADDOP MULOP LOGOP ASSIGN SEMICOLON COMMA LBRACK RBRACK LBRACE RBRACE LPAREN RPAREN COLON

%left ELSE
%left LOGOP
%left RELOP
%left ADDOP
%left MULOP
%right ASSIGN
%right UMINUS

%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int line_number;
extern char *yytext;
void yyerror(const char *s);
void suppress_redundant_errors(const char *error_message);
int err = 0;
int last_error_line = -1;
%}

%token INT FLOAT CHAR DOUBLE RETURN BREAK CONTINUE IF ELSE FOR WHILE DO SWITCH CASE DEFAULT MAIN
%token ID NUM FLOAT_LITERAL CHAR_LITERAL RELOP ADDOP MULOP LOGOP ASSIGN SEMICOLON COMMA LBRACK RBRACK LBRACE RBRACE LPAREN RPAREN COLON

%left ELSE
%left LOGOP
%left RELOP
%left ADDOP
%left MULOP
%right ASSIGN
%right UMINUS

%%
START : Program {
            if (err == 0) {
                printf("Parsing completed successfully.\n");
            } else {
                printf("Parsing completed with errors.\n");
            }
        }
        ;

Program : Declarations MainFunction
        | MainFunction
        | Declarations
        ;

MainFunction : INT MAIN LPAREN RPAREN CompoundStmt
             ;

Declarations : Declarations Declaration
             | Declaration
             ;

Declaration : Type VarList SEMICOLON
            | error SEMICOLON { suppress_redundant_errors("Missing or invalid declaration"); err = 1; yyclearin; }
            ;

Type : INT
     | FLOAT
     | CHAR
     | DOUBLE
     ;

VarList : Variable
        | VarList COMMA Variable
        ;

Variable : ID
         | ID ASSIGN Expression
         | Array
         ;

Array : ID Dimensions
      ;

Dimensions : Dimensions LBRACK NUM RBRACK
           | LBRACK NUM RBRACK
           ;

Statement : CompoundStmt
          | SimpleStmt
          ;

SimpleStmt : Assignment
           | Declaration
           | ReturnStmt
           | BREAK SEMICOLON
           | CONTINUE SEMICOLON
           | error SEMICOLON { suppress_redundant_errors("Invalid statement"); err = 1; yyclearin; }
           ;

CompoundStmt : LBRACE StmtList RBRACE
             ;

StmtList : StmtList Statement
         | /* empty */
         ;

Assignment : ID ASSIGN Expression SEMICOLON
           ;

Expression : Expression ADDOP Expression
           | Expression MULOP Expression
           | Expression RELOP Expression
           | Expression LOGOP Expression
           | Term
           ;

Term : NUM
     | FLOAT_LITERAL
     | CHAR_LITERAL
     | ID
     | LPAREN Expression RPAREN
     | ADDOP Term %prec UMINUS
     ;

SelectionStmt : IF LPAREN Expression RPAREN Statement
              | IF LPAREN Expression RPAREN Statement ELSE Statement
              ;

IterationStmt : WHILE LPAREN Expression RPAREN Statement
              ;

ReturnStmt : RETURN Expression SEMICOLON
           ;

Statement : SelectionStmt
          | IterationStmt
          | SimpleStmt
          | CompoundStmt
          ;

%%
void suppress_redundant_errors(const char *error_message) {
    if (last_error_line != line_number) {
        printf("Error: %s, Line number: %d, Token: '%s'\n", error_message, line_number, yytext[0] ? yytext : "<EOF>");
        last_error_line = line_number;
    }
}

void yyerror(const char *s) {
    suppress_redundant_errors("Syntax error");
}

int main() {
    return yyparse();
}
%%
START : Program {
            if (err == 0) {
                printf("Parsing completed successfully.\n");
            } else {
                printf("Parsing completed with errors.\n");
            }
        }
        ;

Program : Declarations MainFunction
        | MainFunction
        | Declarations
        ;

MainFunction : INT MAIN LPAREN RPAREN CompoundStmt
             ;

Declarations : Declarations Declaration
             | Declaration
             ;

Declaration : Type VarList SEMICOLON
            | error SEMICOLON { suppress_redundant_errors("Missing or invalid declaration"); err = 1; yyclearin; }
            ;

Type : INT
     | FLOAT
     | CHAR
     | DOUBLE
     ;

VarList : Variable
        | VarList COMMA Variable
        ;

Variable : ID
         | ID ASSIGN Expression
         | Array
         ;

Array : ID Dimensions
      ;

Dimensions : Dimensions LBRACK NUM RBRACK
           | LBRACK NUM RBRACK
           ;

Statement : CompoundStmt
          | SimpleStmt
          ;

SimpleStmt : Assignment
           | Declaration
           | ReturnStmt
           | BREAK SEMICOLON
           | CONTINUE SEMICOLON
           | error SEMICOLON { suppress_redundant_errors("Invalid statement"); err = 1; yyclearin; }
           ;

CompoundStmt : LBRACE StmtList RBRACE
             ;

StmtList : StmtList Statement
         | /* empty */
         ;

Assignment : ID ASSIGN Expression SEMICOLON
           ;

Expression : Expression ADDOP Expression
           | Expression MULOP Expression
           | Expression RELOP Expression
           | Expression LOGOP Expression
           | Term
           ;

Term : NUM
     | FLOAT_LITERAL
     | CHAR_LITERAL
     | ID
     | LPAREN Expression RPAREN
     | ADDOP Term %prec UMINUS
     ;

SelectionStmt : IF LPAREN Expression RPAREN Statement
              | IF LPAREN Expression RPAREN Statement ELSE Statement
              ;

IterationStmt : WHILE LPAREN Expression RPAREN Statement
              ;

ReturnStmt : RETURN Expression SEMICOLON
           ;

Statement : SelectionStmt
          | IterationStmt
          | SimpleStmt
          | CompoundStmt
          ;

%%
void suppress_redundant_errors(const char *error_message) {
    if (last_error_line != line_number) {
        printf("Error: %s, Line number: %d, Token: '%s'\n", error_message, line_number, yytext[0] ? yytext : "<EOF>");
        last_error_line = line_number;
    }
}

void yyerror(const char *s) {
    suppress_redundant_errors("Syntax error");
}

int main() {
    return yyparse();
}
