#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char *data;
    int top;
    int maxSize;
}STACKI;

void creatStack(STACKI * stack, int maxSize){
    stack -> top =-1;
    stack -> maxSize = maxSize;
    stack -> data = (char*)malloc(sizeof(char)*maxSize);
}

int isemp(STACKI *stack){
    return ((stack-> top )== -1);
}

void push(STACKI* stack, char c){
    stack -> data [++stack -> top ] = c;
}
char pop(STACKI* stack) {
    if (isemp(stack)) {
        // printf("Stack is empty\n");
        return -1;
    }
    char popped = stack -> data [stack -> top--];
    return popped;
}

int calculateResult(const char *input)
{
    // Write your code here
    int res = 0;
    int n = 0;
    int prod = 1;
    STACKI stack;
    creatStack(&stack, strlen(input));

    for (int i = 0; input[i]!= '\0'; i++){
        char rnc = input[i];
        if (rnc >= '0' && rnc <= '9'){
            n = n * 10 + (rnc - 0);
        }else if ( rnc == 'P'){
            push(&stack, 'P');
        }else if (rnc == 'E'){
           while (!isemp(&stack)&& stack.data[stack.top] != 'P'){
            prod *= (stack.data[stack.top]-'0');
            pop(&stack);
           } res += prod;
            if (!isemp(&stack) && stack.data[stack.top] == 'P'){
                pop(&stack);
            }
        }else{
        }
    }   free(stack.data);
    return res; 
}

// Driver code
int main()
{
    char input[100];
    scanf("%s", input);
    printf("%d", calculateResult(input));
    return 0;
}