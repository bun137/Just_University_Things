#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  struct node *left;
  char data;
  struct node *right;
} NODE;

typedef struct stack {
  NODE *arr[64];
  int top;
} STK;

void push(STK *stack, NODE *data) { stack->arr[++stack->top] = data; }

NODE *pop(STK *stack) { // pop function!!
  return stack->arr[stack->top--];
}

int isOperator(char ch) {
  return (ch == '+' || ch == '*' || ch == '/' || ch == '-');
}

NODE *createNode(char ch) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = ch;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

NODE *constructTree(char *postflix_exp) {
  STK stack;
  stack.top = -1;
  while (*postflix_exp != '\0') {
    if (isOperator(*postflix_exp)) {
      NODE *popOp1 = pop(&stack);
      NODE *popOp2 = pop(&stack);
      NODE *newNode = createNode(*postflix_exp);
      newNode->right = popOp1;
      newNode->left = popOp2;
      push(&stack, newNode);
    } else {
      push(&stack, createNode(*postflix_exp));
    }
    postflix_exp++;
  }
  return pop(&stack);
}
// abc*+ == a + b * c
//      +
//    a    *
//       b     c

int eval(int op1, int op2, char operandi) {
  switch (operandi) {
  case '+':
    return (op1 + op2);
  case '-':
    return (op1 - op2);
  case '/':
    return (op1 / op2);
  case '*':
    return (op1 * op2);
  default:
    printf("returning 0 in eval \n");
    return 0;
    break;
  }
}

int getValue(NODE *current) {
  if (current->left == NULL && current->right == NULL) {
    int value;
    printf("Enter the value of the variable %c:", current->data);
    scanf("%d", &value);
    return value;
  }
  int left = getValue(current->left);
  int right = getValue(current->right);
  printf("values going to eval function are %d %d %c \n", left, right,
         current->data);
  return eval(left, right, current->data);
}

void printTree(NODE *tree) {
  if (tree == NULL) {
    return;
  }
  printTree(tree->left);
  printf("%c ", tree->data);
  printTree(tree->right);
}

int main(int argc, char *argv[]) {
  char postflix_exp[64];
  printf("Enter the postflix expression: ");
  scanf("%s", postflix_exp);

  NODE *tree = constructTree(postflix_exp);
  printTree(tree);
  printf("\n");
  printf("The result is %d\n", getValue(tree));

  return EXIT_SUCCESS;
}
