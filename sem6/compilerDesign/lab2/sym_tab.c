#include "sym_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;

int get_size_for_type(int type) {
    switch(type) {
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

int insert_symbol(const char* name, int type, int line_number, int scope, int is_function) {
    if (symbol_count >= MAX_SYMBOLS) {
        printf("Error: Symbol table full\n");
        return -1;
    }

    Symbol* symbol = &symbol_table[symbol_count];
    strncpy(symbol->name, name, MAX_NAME_LENGTH);
    symbol->name[MAX_NAME_LENGTH] = '\0';
    symbol->type = type;
    symbol->size = get_size_for_type(type); // ✅ Assign correct size
    symbol->line_number = line_number;
    symbol->scope = scope;
    symbol->is_function = is_function;

    return symbol_count++;
}

Symbol* lookup_symbol(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

void display_symbol_table() {
    printf("\nValid Syntax\n");
    printf("Symbol Table:\n");
    printf("Name\tSize\tType\tLine No.\tScope\n");

    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_function) {
            printf("%s\t%d\t%d\t%d\t%d\n",
                   symbol_table[i].name, symbol_table[i].size, symbol_table[i].type,
                   symbol_table[i].line_number, symbol_table[i].scope);
        }
    }
}

void free_symbol_table() {
    symbol_count = 0;
}
