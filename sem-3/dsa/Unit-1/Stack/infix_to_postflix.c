#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node *next;
} STACKI_LINKEDD;

typedef struct Stack {
  struct Node *top;
} Stack;

STACKI_LINKEDD *newNode(char data) {
  STACKI_LINKEDD *node = (STACKI_LINKEDD *)malloc(sizeof(STACKI_LINKEDD));
  node->data = data;
  node->next = NULL;
  return node;
}

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

int isEmpty(Stack *stack) { return stack->top == NULL; }

void push(Stack *stack, char data) {
  STACKI_LINKEDD *node = newNode(data);
  node->next = stack->top;
  stack->top = node;
}

char pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }
  STACKI_LINKEDD *temp = stack->top;
  char popped = temp->data;
  stack->top = temp->next;
  free(temp);
  return popped;
}

char peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->top->data;
}

void display(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }
  STACKI_LINKEDD *temp = stack->top;
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int icp(char token) {
  switch (token) { // could have used ENAMS lol!
  case '(':
    return 40;
    break;

  case '$':
    return 30;
    break;

  case '*':
    return 20;
    break;

  case '/':
    return 20;
    break;

  case '%':
    return 20;
    break;

  case ')':
    return 10;
    break;

  case '-':
    return 10;
    break;

  default:
    printf("\n hehe not valid \n");
    break;
  }
}

int isp(char token) {
  switch (token) { // could have used ENUMS lol
  case '#':
    return -1;
    break;

  case '(':
    return 0;
    break;

  case '$':
    return 35;
    break;

  case '*':
    return 20;
    break;

  case '/':
    return 20;
    break;

  case '%':
    return 20;
    break;

  case ')':
    return 10;
    break;

  case '-':
    return 10;
    break;

  default:
    printf("\n hehe not valid \n");
    break;
  }
}

void infix_to_postfix(char *inexp, char *outexp) {
  int i = 0, k = 0;
  char token;
  Stack stack;
  stack = *createStack();
  createStack(&stack);
  push(&stack, '#');
  token = inexp[i]; // get the first token

  while (token != '\0') {
    if (isalnum(token)) { // to check if token is an operand -> 'a,b,c,...., z ,
                          // 1,2,3,...., inf' , is it? alphabet or num
      outexp[k++] = token;
    } else {              // it is an operator
      if (token == ')') { // right bracket -> go to the stack and remove all the
                          // operands till you reach the left bracket
        while (peek(&stack) != '(') {
          outexp[k++] = pop(&stack);
        }
        pop(&stack);
      } else { // either left bracket or any operator
        while (isp(peek(&stack)) >= icp(token)) {
          outexp[k++] = pop(&stack);
        }
        push(&stack, token); // push the curent token
      }
    }
    token = inexp[++i];
  } // comes out of the while loop bc token = '\0', there might be stuff left in
    // the stack
  while (peek(&stack) != '#') {
    outexp[k++] = pop(&stack);
  }
  outexp[k] = '\0';
}

int main() {
  Stack *stack = createStack();
  char inexp[100];
  char outexp[100];
  printf("Enter an infix expression: ");
  fgets(inexp, sizeof(inexp), stdin);
  infix_to_postfix(inexp, outexp); // Call the function to modify outexp
  printf("Postfix expression: %s\n", outexp);

  // int choice;
  // while (1) {
  //     printf("\nPerform operations on the stack:");
  //     printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
  //     printf("\n\nEnter the choice: ");
  //     scanf(" %d", &choice);
  //     switch (choice) {
  //         case 1:
  //             char data;
  //             printf("\nEnter the element to be added onto the stack: ");
  //             scanf(" %c", &data);
  //             push(stack, data);
  //             display(stack);
  //             break;
  //         case 2:
  //             pop(stack);
  //             display(stack);
  //             break;
  //         case 3:
  //             display(stack);
  //             break;
  //         case 4:
  //             exit(0);
  //         default:
  //             printf("\nInvalid choice!!");
  //     }
  // }
  return 0;
}
