#include "sym_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

int get_size_for_type(int type) {
    switch (type) {
        case 1: return 1; // char
        case 2: return 4; // int
        case 3: return 4; // float
        case 4: return 8; // double
        default: return 0;
    }
}

void init_symbol_table() {
    symbol_count = 0;
    memset(symbol_table, 0, sizeof(symbol_table));
}

int insert_symbol(const char *name, int type, int line_number, int scope, int is_function, double value) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Error: Symbol table full\n");
        return -1;
    }

    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0 && symbol_table[i].scope == scope) {
            return -1;  // Redeclaration error
        }
    }

    Symbol *symbol = &symbol_table[symbol_count++];
    strncpy(symbol->name, name, MAX_NAME_LENGTH);
    symbol->name[MAX_NAME_LENGTH] = '\0';
    symbol->type = type;
    symbol->size = get_size_for_type(type);
    symbol->line_number = line_number;
    symbol->scope = scope;
    symbol->is_function = is_function;
    symbol->value = value;

    return symbol_count - 1;
}

Symbol *lookup_symbol(const char *name, int scope) {
    for (int i = symbol_count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

void update_symbol(const char *name, double value) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            symbol_table[i].value = value;
            return;
        }
    }
}

void display_symbol_table() {
    printf("\nValid syntax\n");
    
    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n",
           "Name", "Size", "Type", "Line No.", "Scope", "Value");

    for (int i = 0; i < symbol_count; i++) {
        printf("%-10s %-10d %-10d %-10d %-10d %-.6f\n",
               symbol_table[i].name,
               symbol_table[i].size,
               symbol_table[i].type,
               symbol_table[i].line_number,
               symbol_table[i].scope,
               symbol_table[i].value);
    }
}

void free_symbol_table() {
    symbol_count = 0;
}
