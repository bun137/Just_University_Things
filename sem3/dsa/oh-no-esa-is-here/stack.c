#include<stdio.h>
#include<stdlib.h>
#define MAX 64
typedef struct stack{
 int arr[MAX];
  int top;
} STK;

void push(STK* stk, int data){
  stk->top++;
  stk->arr[stk->top] = data;
}

int pop(STK* stk){
  if(stk->top == -1){
    printf("theres nothing here to pop!!!\n");
  return -1;
  }
  int ele = stk->arr[stk->top]; 
  stk->top--;
  return ele;
}

int isEmpty(STK* stk){
  return (stk->top == -1);
}

void display(STK* stk){
for(int k = 0; k<=stk->top;k++){
    printf("%d\t",stk->arr[k]);
  }
}

int main(int argc, char *argv[])
{
  STK stk;
  stk.top = -1;
 //menu driven program 
  int choice;
  int data;
  while(1){
    printf("\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. isEmpty\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter the data: ");
        scanf("%d", &data);
        push(&stk, data);
        display(&stk);
          break;
      case 2:
        data = pop(&stk);
        if(data != -1){
          printf("Popped data: %d\n", data);
        }
        display(&stk);
        break;
      case 3:
        if(isEmpty(&stk)){
          printf("Stack is empty\n");
        }else{
          printf("Stack is not empty\n");
        }
        display(&stk);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}

