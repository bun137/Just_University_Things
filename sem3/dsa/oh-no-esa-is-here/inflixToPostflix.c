// and yes INFLIX LIKE NETFLIX cause I wanna relax and watch my lil show and
// enjoy eating chicken popcorn BUT NO ESA IS HERE!

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StackLinked {
  char data;
  struct StackLinked *ptrNext;
} STACKI;

void push(STACKI **stkL,
          char data) { // extra masala createnode + insertfront function
  STACKI *newNode = (STACKI *)malloc(sizeof(STACKI));
  newNode->data = data;
  newNode->ptrNext = (*stkL);
  *stkL = newNode;
}

int pop(STACKI **stkL) { // extra masala deletefront function
  if (*stkL == NULL) {
    printf("theres nothing in the stack to pop, its empty! \n");
    return -1;
  }
  STACKI *temp = *stkL;
  *stkL = (*stkL)->ptrNext;
  char a = temp->data;
  free(temp);
  return a;
}

int getPriority(char ch, int isInsideS) {
  switch (ch) {
  case '(':
    return 10;
  case '^':
    if (isInsideS == 1) {
      return 60;
    } else {
      return 55;
    }
  case '-':
    return 20;
  case '+':
    return 30;
  case '*':
    return 40;
  case '/':
    return 50;
  case '#':
    return -1;
  default:
    return -1;
  }
}

char peek(STACKI **stk) {
  if (*stk == NULL) {
    return -1;
  }
  return (*stk)->data;
}

char *iToP(char *expr) {
  STACKI *stk = NULL;
  int counter = 0;
  push(&stk, '#');
  char *pexp = malloc(sizeof(char) * 64);
  while (*expr != '\0') {
    if (isalpha(*expr)) {
      pexp[counter] = *expr;
      counter++;
      expr++;
    } else {
      if (*expr == ')') {
        char ch;
        while (peek(&stk) != '(') {
          ch = pop(&stk);
          pexp[counter] = ch;
          counter++;
        }
        pop(&stk);
        expr++;
        continue;
      } else {
        char chi;
        while (getPriority(peek(&stk), 1) > getPriority(*expr, 0)) {
          chi = pop(&stk);
          pexp[counter++] = chi;
        }
        push(&stk, *expr);
        expr++;
      }
    }
  }
  char ch;
  while (peek(&stk) != '#') {
    ch = pop(&stk);
    pexp[counter] = ch;
    counter++;
  }
  pexp[counter] = '\0';
  return pexp;
}

int main(int argc, char *argv[]) {
  STACKI *stack = NULL;
  char infix_expr[64];
  printf("Enter infix expression: ");
  scanf("%s", infix_expr);
  char *postfix_expr = iToP(infix_expr);
  printf("Postfix Expression: %s\n", postfix_expr);
  return EXIT_SUCCESS;
}
