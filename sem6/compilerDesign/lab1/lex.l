%{
#include <stdio.h>
#include "parser.tab.h"

// Track line numbers
int line_number = 1;
%}

%%
\n                          { line_number++; }           // Increment line number on newlines
"int"                       { return INT; }
"float"                     { return FLOAT; }
"char"                      { return CHAR; }
"double"                    { return DOUBLE; }
"return"                    { return RETURN; }
"break"                     { return BREAK; }
"continue"                  { return CONTINUE; }
"if"                        { return IF; }
"else"                      { return ELSE; }
"for"                       { return FOR; }
"while"                     { return WHILE; }
"do"                        { return DO; }
"switch"                    { return SWITCH; }
"case"                      { return CASE; }
"default"                   { return DEFAULT; }
"main"                      { return MAIN; }

[a-zA-Z_][a-zA-Z0-9_]*      { return ID; }             // Matches identifiers
[0-9]+\.[0-9]+              { return FLOAT_LITERAL; }  // Matches floating-point numbers
[0-9]+                      { return NUM; }            // Matches integers
"'"[a-zA-Z]"'"              { return CHAR_LITERAL; }   // Matches character literals like 'a'
"<"|"<="|">"|">="|"=="|"!=" { return RELOP; }          // Relational operators
"+"|"-"                     { return ADDOP; }          // Addition/subtraction
"*"|"/"|"%"                 { return MULOP; }          // Multiplication/division
"!"|"&&"|"||"               { return LOGOP; }          // Logical operators
"="                         { return ASSIGN; }         // Assignment operator
";"                         { return SEMICOLON; }      // Semicolon
","                         { return COMMA; }          // Comma
"["                         { return LBRACK; }         // Left bracket
"]"                         { return RBRACK; }         // Right bracket
"{"                         { return LBRACE; }         // Left brace
"}"                         { return RBRACE; }         // Right brace
"("                         { return LPAREN; }         // Left parenthesis
")"                         { return RPAREN; }         // Right parenthesis
[ \t]+                      ;                          // Ignore whitespace
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignore multi-line comments */ }
"//".*                      { /* Ignore single-line comments */ }
.                           { return yytext[0]; }      // Catch-all rule for other tokens
%%

int yywrap() {
    return 1;
}
