#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} STACKI_LINKEDD;

typedef struct Stack {
    struct Node* top;
} Stack;

STACKI_LINKEDD* newNode(int data) {
    STACKI_LINKEDD* node = (STACKI_LINKEDD*) malloc(sizeof(STACKI_LINKEDD));
    node->data = data;
    node->next = NULL;
    return node;
}

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    STACKI_LINKEDD* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    STACKI_LINKEDD* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    STACKI_LINKEDD* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    int choice;
    while (1) {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                int data;
                printf("\nEnter the element to be added onto the stack: ");
                scanf("%d", &data);
                push(stack, data);
                display(stack);
                break;
            case 2:
                pop(stack);
                display(stack);
                break;
            case 3:
                display(stack);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!!");
        }
    }
    return 0;
}



