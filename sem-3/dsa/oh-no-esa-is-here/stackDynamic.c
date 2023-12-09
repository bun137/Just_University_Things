#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int capacity;
  int *ptrTopArr;
} STK;

void createStack(STK *stk) {
  printf("what your capacity?!: ");
  scanf("%d", &stk->capacity);
  stk->ptrTopArr = malloc(sizeof(int) * stk->capacity);
  stk->top = -1;
}

int isPura(STK *stk) { return (stk->top == stk->capacity); }

void push(STK *stk, int data) {
  stk->top++;
  if (isPura(stk)) {
    printf("stack is full, going ralloc memory\n");
    stk->ptrTopArr = realloc(stk->ptrTopArr, 2 * sizeof(int) * stk->capacity);
    stk->capacity *= 2;
  }
  stk->ptrTopArr[stk->top] = data;
}
int isKhali(STK *stk) { return stk->top == -1; }

int pop(STK *stk) {
  if (isKhali(stk)) {
    printf("Stack is emptyyyy!\n");
    return -1;
  }
  int ele = stk->ptrTopArr[stk->top];
  stk->top--;
  return ele;
}

void display(STK *stk) {
  if (isKhali(stk)) {
    printf("the stack is emptyy!\n");
  } else {
    for (int i = stk->top; i >= 0; i--) {
      printf("%d\n", stk->ptrTopArr[i]);
    }
  }
}
int main(int argc, char *argv[]) {
  // menu driven program
  STK stk;
  createStack(&stk);
  int choice;
  int data;

  while (1) {
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. exit\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("enter data: ");
      scanf("%d", &data);
      push(&stk, data);
      display(&stk);
      break;
    case 2:
      printf("poped element is: %d\n", pop(&stk));
      display(&stk);
      break;
    case 3:
      exit(0);
    default:
      printf("invalid choice\n");
    }
  }

  return EXIT_SUCCESS;
}
