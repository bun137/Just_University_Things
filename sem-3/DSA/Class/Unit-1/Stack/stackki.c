#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top_ele;
    int capaci;
    int *ptr_to_top;
}STACKI;

void createstacki(STACKI *ptr_to_sti){
    scanf("%d", &(ptr_to_sti->capaci));
    ptr_to_sti->ptr_to_top = malloc(sizeof(int) * ptr_to_sti->capaci);
    ptr_to_sti->top_ele = -1;
}


int isfull(STACKI sti){
    if (sti.top_ele == sti.capaci - 1){
        return 1;
    }else{
        return 0;
    }
}

int isempty(STACKI sti){ // IF EMPTY RETURN 1
    return(sti.top_ele == -1);
}

int pushi(STACKI *ptr_to_sti, int top_ele){
    if (isfull(*ptr_to_sti)){
        return -1;
    }else{
        (ptr_to_sti->top_ele)++;
        ptr_to_sti->ptr_to_top[ptr_to_sti->top_ele] = top_ele;
    }
}

int pop(STACKI * ptr_to_sti){
    int ele;
    if(isempty(*ptr_to_sti)){
        return -1;
    }else{
        ele = ptr_to_sti->ptr_to_top[ptr_to_sti->top_ele];
        (ptr_to_sti->top_ele)--;
        return ele;
    }
}

void display(STACKI *ptr_to_sti){
    if(isempty(*ptr_to_sti)){
        printf("Empty Stackiii");
    }else{
        int i;
        for(i = ptr_to_sti->top_ele; i >= 0; i--){
            printf("%d ", ptr_to_sti->ptr_to_top[i]);
        }
    }
}


int peek(STACKI *ptr_to_sti){
    if(isempty(*ptr_to_sti)){
        printf("Empty Stackiii");
    }
    else{
        return (ptr_to_sti->ptr_to_top[ptr_to_sti->top_ele]);
    }
}


void destroyi(STACKI *ptr_to_sti){
    free(ptr_to_sti->ptr_to_top);
    ptr_to_sti->ptr_to_top = NULL;
    ptr_to_sti->top_ele = -1;
    ptr_to_sti->capaci = 0;
}

int main() {
    STACKI sti;
    int choice, ele;

    printf("Enter the capacity of the array: ");
    scanf("%d", &(sti.capaci));

    createstacki(&sti);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &ele);
                if (pushi(&sti, ele) == -1) {
                    printf("Stack is full. Cannot push element.\n");
                } else {
                    printf("Element %d pushed to the stack.\n", ele);
                    display(&sti);
                    printf("\n");
                }
                break;
            case 2:
                if (isempty(sti)) {
                    printf("Stack is empty. Cannot pop element.\n");
                } else {
                    ele = pop(&sti);
                    printf("Popped element: %d\n", ele);
                    display(&sti);
                    printf("\n");
                }
                break;
            case 3:
                printf("Stack elements: ");
                display(&sti);
                printf("\n");
                break;
            case 4:
                ele = peek(&sti);
                if (ele != -1) {
                    printf("Top element: %d\n", ele);
                }
                break;
            case 0:
                printf("Exiting...\n");
                destroyi(&sti);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
