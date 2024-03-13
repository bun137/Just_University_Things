#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_EXP_SIZE 128
typedef struct node{
  char data;
  struct node* left;
  struct node* right;
} node_t;


typedef struct stack{
  node_t* data_arr[MAX_EXP_SIZE];
  int top;
} stk;


// stack functions
void push(stk* stack, node_t* data);
node_t* pop(stk* stack);


// tree functions
node_t* construct_tree(char *postfix_exp);
int getValue(node_t* tree);
int eval(int op1, int op2, char operand);
void print_tree(node_t* tree);

// helper functions
int isOperator(char ch);
node_t* getNode(char ch);


int main(int argc, char *argv[])
{
  char postfix_exp[MAX_EXP_SIZE];
  printf("Enter postfix expression without spaces: ");
  scanf("%s", postfix_exp);

  node_t*  tree = construct_tree(postfix_exp);
  print_tree(tree);
  printf("\n");
  int value = getValue(tree);
  printf("The result = %d\n", value);

  return EXIT_SUCCESS;
}


void push(stk* stack, node_t* data){
  stack->data_arr[++stack->top] = data;
}
node_t* pop(stk* stack){
  return stack->data_arr[stack->top--];
}


node_t* construct_tree(char* postfix_exp){
  stk stack = {.top = -1};
  while(*postfix_exp != '\0'){
    if(isOperator(*postfix_exp)){
      node_t* op1 = pop(&stack);
      node_t* op2 = pop(&stack);
      node_t* new_node = getNode(*postfix_exp);
      new_node->right = op1;
      new_node->left = op2;
      push(&stack, new_node);
    } else{
      push(&stack, getNode(*postfix_exp));
    }
    postfix_exp++;
  }
  return pop(&stack);
}

int getValue(node_t* current){
  // leaf node, aka operand
  if(current->left == NULL && current->right == NULL){
    int value;
    printf("Enter the value for variable %c: ", current->data);
    scanf("%d", &value);
    return value;
  }

  // else
  int left = getValue(current->left);
  int right = getValue(current->right);
  printf("passing values %d %d %c to eval\n", left, right, current->data);
  return eval(left, right, current->data);
}


int eval(int op1, int op2, char operand){
  switch(operand) {
    case '+': return op1+op2;
    case '-': return op1-op2;
    case '*': return op1*op2;
    case '/': return op1/op2;
    default: 
      printf("returning 0 in eval\n");
      return 0;
      break;
  }
}

int isOperator(char ch){
  return (ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

node_t* getNode(char ch){
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = ch;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void print_tree(node_t* tree){
  if(tree == NULL){
    return;
  }
  print_tree(tree->left);
  printf("%c ", tree->data);
  print_tree(tree->right);
}
