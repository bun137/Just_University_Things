%{
    #define YYSTYPE char*
    #include <unistd.h>
    #include "y.tab.h"
    #include <stdio.h>
    #include <stdlib.h> // Needed for strdup

    extern void yyerror(const char *); // Declare error handling function
%}

/* Regular definitions */
digit       [0-9]
letter      [a-zA-Z]
id          {letter}({letter}|{digit})*
digits      {digit}+
opFraction  (\.{digits})?
opExponent  ([Ee][+-]?{digits})?
number      {digits}{opFraction}?{opExponent}?

%option yylineno

%%

\/\/.*                        ; // Ignore comments
[\t\n\r ]+                    ; // Ignore whitespaces

"("                            { return '('; }
")"                            { return ')'; }
"."                            { return '.'; }
","                            { return ','; }
"*"                            { return '*'; }
"+"                            { return '+'; }
";"                            { return ';'; }
"-"                            { return '-'; }
"/"                            { return '/'; }
"="                            { return '='; }
">"                            { return '>'; }
"<"                            { return '<'; }

"if"                           { return T_IF; }
"else"                         { return T_ELSE; }
"do"                           { return T_DO; }
"while"                        { return T_WHILE; }

{number}   { 
              yylval = strdup(yytext);
              return T_NUM;
           }

{id}       { 
              yylval = strdup(yytext);
              return T_ID;
           }

.          { /* Ignore any other characters */ }

%%
