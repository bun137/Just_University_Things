#include "quad_generation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quad_code_gen(char *a, char *b, char *op, char *c) {
  printf("%s %s %s %s\n", a, b, op, c);
}

char *new_temp() // returns a pointer to a new temporary
{
  char *temp = (char *)malloc(sizeof(char) * 4);
  sprintf(temp, "t%d", temp_no);
  ++temp_no;
  return temp;
}
