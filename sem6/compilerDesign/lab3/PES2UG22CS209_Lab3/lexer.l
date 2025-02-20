%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "sym_tab.h"

int line_number = 1;
int current_scope = 0;
%}

%%

[ \t]+                ;               /* Ignore whitespace */
\n                    { line_number++; }
"int"                 { return T_INT; }
"float"               { return T_FLOAT; }
"double"              { return T_DOUBLE; }
"char"                { return T_CHAR; }
"main"                { return T_MAIN; }
"{"                   { current_scope++; return '{'; }
"}"                   { current_scope--; return '}'; }
"("                   { return '('; }
")"                   { return ')'; }
[a-zA-Z][a-zA-Z0-9]*   { 
                          yylval.str = strdup(yytext); 
                          return T_ID; 
                      }
[0-9]+\.[0-9]+        { 
                          yylval.str = strdup(yytext); 
                          return T_NUM; 
                      }
[0-9]+                { 
                          yylval.str = strdup(yytext); 
                          return T_NUM; 
                      }
\"[^\"]*\"            { 
                          yylval.str = strdup(yytext); 
                          return T_STRLITERAL; 
                      }
"="                   { return '='; }
"+"                   { return '+'; }
"-"                   { return '-'; }
"*"                   { return '*'; }
"/"                   { return '/'; }
";"                   { return ';'; }
.                     { printf("Unknown character: %s\n", yytext); }

%%

int yywrap(void) {
    return 1;
}
