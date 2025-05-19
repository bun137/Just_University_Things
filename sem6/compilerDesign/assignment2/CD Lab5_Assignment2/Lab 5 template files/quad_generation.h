#ifndef QUAD_GENERATION_H
#define QUAD_GENERATION_H

#include <stdio.h>  // Ensure FILE is defined

extern FILE* icg_quad_file;  // Correct declaration
extern int temp_no;  // Variable to track temp count

void quad_code_gen(char* a, char* b, char* op, char* c);
char* new_temp();
void quad_if_else(char* condition, char* true_label, char* false_label);
void quad_do_while(char* condition, char* loop_start, char* loop_end);

#endif  // QUAD_GENERATION_H
