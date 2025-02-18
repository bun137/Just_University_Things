#ifndef SYM_TAB_H
#define SYM_TAB_H

#define MAX_SYMBOLS 100
#define MAX_NAME_LENGTH 31

typedef struct {
  char name[MAX_NAME_LENGTH + 1];
  int type;
  int size;
  int line_number;
  int scope;
  int is_function;
} Symbol;

// 1: char, 2: int, 3: float, 4: double
// size in bytes
// 0 for variables, 1 for functions

void init_symbol_table();
int insert_symbol(const char *name, int type, int line_number, int scope,
                  int is_function);
Symbol *lookup_symbol(const char *name, int scope);
void display_symbol_table();
void free_symbol_table();

#endif
