#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    char data;
    struct node * next;
    struct node * top;
}NODEE;

NODEE* createStack() {
    NODEE* top = (NODEE*) malloc(sizeof(NODEE));
    NODEE->top = NULL;
    
}
