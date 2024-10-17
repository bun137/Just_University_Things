#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1024
typedef struct node {
  struct node *right;
  struct node *left;
  char data;
} NODEE;

typedef struct stack {
  NODEE *arr[MAX_SIZE];
  int top;
} STACKKII;

NODEE *createNode(char data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

NODEE *pop(STACKKII *stack) {
  NODEE *node = stack->arr[stack->top];
  (stack->top)--;
  return node;
}

int areYouOp(char exp) {
  return (exp == '+' || exp == '-' || exp == '*' || exp == '/');
}

void buildTree(NODEE **plant, char *exp) {
  STACKKII *stack = malloc(sizeof(STACKKII));
  stack->top = -1;
  while (*exp != '\0') {
    if (areYouOp(*exp)) {
      NODEE *op1 = pop(stack);
      NODEE *op2 = pop(stack);
      NODEE *newNode = createNode(*exp);
      newNode->right = op1;
      newNode->left = op2;
      stack->arr[++(stack->top)] = newNode;
    } else {
      NODEE *newNode = createNode(*exp);
      stack->arr[++(stack->top)] = newNode;
    }
    exp++;
  }
  *plant = pop(stack);
}

int eval(NODEE *plant) {
  if (areYouOp(plant->data)) {
    switch (plant->data) {
    case '+':
      return eval(plant->left) + eval(plant->right);
    case '-':
      return eval(plant->left) - eval(plant->right);
    case '/':
      return eval(plant->left) / eval(plant->right);
    case '*':
      return eval(plant->left) * eval(plant->right);
    }
  } else {
    // int input;
    // int newVar = plant->data;
    // printf("enter the value for %c ", newVar);
    // scanf("%d", &input);
    return atoi(&plant->data);
  }
}

int main() {
  char exp[MAX_SIZE];
  printf("heyy enter the postfix expression: ");
  scanf("%s", exp);
  NODEE *plant;
  buildTree(&plant, exp);
  printf("Evaluation of the postfix expresionnnnn issss tantada %d",
         eval(plant));
}
