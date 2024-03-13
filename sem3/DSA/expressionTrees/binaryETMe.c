#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *llink;
    int info;
    struct node *rlink;
}NODEE;

typedef struct tree{
    struct tree *root_ptr;
}TREEI;

typedef struct stack{ // stack implementation using arrays :skull:
    NODEE *arrayForSt[30];
    int topOfStack;
}STACKII;

