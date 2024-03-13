#include <stdio.h>
#include <stdlib.h>

typedef struct csll_node{
    int data;
    struct csll_node* ptr_to_next;
}NODEE;

// typedef struct csll{
//     NODEE* tail;
// }CSLL;
// CSLL* csll;
// csll -> tail;
void insertfront(NODEE**tail, int data){
    NODEE* newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode->data = data;
    if (*tail == NULL){// csll is emptyy
        *tail = newnode;
        newnode -> ptr_to_next = newnode;
    }else{
        newnode -> ptr_to_next = (*tail) -> ptr_to_next ;
        (*tail)-> ptr_to_next = newnode;
    }
}

void insertback(NODEE **tail, int data){
    NODEE* newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode->data = data;
    if(*tail == NULL){
        insertfront(tail, data);
    }else{
        newnode -> ptr_to_next = (*tail)-> ptr_to_next;
        (*tail)-> ptr_to_next = newnode;
        *tail = newnode;
    }
}

void deletefront(NODEE** tail){
    if (*tail == NULL){
        printf("\nempty list\n");
    }
    NODEE *start = (*tail)-> ptr_to_next;
    if(start == *tail){
        *tail = NULL;        
    }else{
        (*tail)-> ptr_to_next = start -> ptr_to_next;
    }
    free(start);
    start = NULL;
}

void deleteback(NODEE **tail){
    if (*tail == NULL){
        printf("emptyy list here\n");
        return ;
    }
    NODEE *start = (*tail)-> ptr_to_next;
    if(start == *tail){
        free(*tail);
        (*tail) = NULL;
    }
    else{
        NODEE*dtail;
        dtail = *tail;
        while(dtail->ptr_to_next != *tail){
            dtail = dtail -> ptr_to_next;
        }
        dtail -> ptr_to_next = (*tail) -> ptr_to_next;
        free(*tail);
        *tail = dtail;
    }
}


void display(NODEE* tail){

    if(tail == NULL){
        printf("Empty List\n");
        return;
    }
    NODEE* start = tail-> ptr_to_next;

    while(start != tail){
        printf("%d ", start->data);
        start = start->ptr_to_next;
    }
    printf("%d \n", tail->data);
}

int main() {
    NODEE* tail = NULL;
    int choice, data;

    do {
        printf("\nCircular Singly Linked List Operations\n");
        printf("1. Insert at the front\n");
        printf("2. Insert at the back\n");
        printf("3. Delete from the front\n");
        printf("4. Delete from the back\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertfront(&tail, data);
                break;
            case 2:
                printf("Enter data to insert at the back: ");
                scanf("%d", &data);
                insertback(&tail, data);
                break;
            case 3:
                deletefront(&tail);
                break;
            case 4:
                deleteback(&tail);
                break;
            case 5:
                display(tail);
                break;
            case 6:
                printf("Exiting...\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}