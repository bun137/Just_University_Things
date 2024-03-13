#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int *data;
    int top;
    int maxSize;
};

void initStack(struct Stack *stack, int maxSize) {
    stack->data = (int *)malloc(sizeof(int) * maxSize);
    stack->top = -1;
    stack->maxSize = maxSize;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int num) {
    stack->data[++stack->top] = num;
}

int pop(struct Stack *stack) {
    return stack->data[stack->top--];
}

int calculateResult(const char *input) {
    int result = 0;
    int num = 0;
    struct Stack stack;
    initStack(&stack, strlen(input));

    for (int i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];

        if (currentChar >= '0' && currentChar <= '9') {
            num = num * 10 + (currentChar - '0');
        } else if (currentChar == 'P') {
            push(&stack, num);
            num = 0;
        } else if (currentChar == 'E') {
            int product = 1;
            while (!isEmpty(&stack) && stack.data[stack.top] != 'P') {
                product *= pop(&stack);
            }
            result += product;

            // Pop the 'P' if present
            if (!isEmpty(&stack) && stack.data[stack.top] == 'P') {
                pop(&stack);
            }
        }
    }

    free(stack.data);
    return result;
}

int main() {
    char input[100];
    scanf("%s", input);
    printf("%d\n", calculateResult(input));
    return 0;
}
