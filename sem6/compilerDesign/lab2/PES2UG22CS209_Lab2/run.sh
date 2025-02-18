#!/bin/bash

rm -f lex.yy.c y.tab.c y.tab.h a.out

lex lexer.l
yacc -d parser.y -Wno
gcc -g y.tab.c lex.yy.c sym_tab.c -lfl 

./a.out < sample_input1.c > output.txt

