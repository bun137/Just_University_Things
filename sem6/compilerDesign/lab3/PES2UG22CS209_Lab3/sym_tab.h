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
  double value;  // Store variable value
} Symbol;

void init_symbol_table();
int insert_symbol(const char *name, int type, int line_number, int scope, int is_function, double value);
Symbol *lookup_symbol(const char *name, int scope);
void update_symbol(const char *name, double value);
void display_symbol_table();
void free_symbol_table();

#endif
