%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
#include "sym_tab.h"

int line_number = 1;
int current_scope = 0;
%}

%%
[ \t]          ;  // Ignore whitespace

\n            { line_number++; }

"int"         { return INT; }
"float"       { return FLOAT; }
"double"      { return DOUBLE; }
"char"        { return CHAR; }
"void"        { return VOID; }

"{"           { current_scope++; return '{'; }
"}"           { current_scope--; return '}'; }

"("           { return '('; }
")"           { return ')'; }

[a-zA-Z][a-zA-Z0-9]*  {
    yylval.string_val = strdup(yytext);
    return IDENTIFIER;
}

[0-9]+  {
    yylval.int_val = atoi(yytext);
    return INTEGER_LITERAL;
}

[0-9]+\.[0-9]+  {
    yylval.float_val = atof(yytext);
    return FLOAT_LITERAL;
}

\'[^\']\'  {
    yylval.string_val = strdup(yytext);
    return CHAR_LITERAL;
}

[;,=]  { return yytext[0]; }

.     { printf("Unknown character: %s\n", yytext); }

%%
int yywrap() {
    return 1;
}
