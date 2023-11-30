#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* ptr_to_next;
} NODEE;

void insertfront(NODEE** dtail, int data) {
    NODEE* newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode->data = data;
    if (*dtail == NULL) {
        printf("\nempty list\n");
        *dtail = newnode;
        newnode->ptr_to_next = newnode;
    }
    else {
        newnode->ptr_to_next = (*dtail) ->ptr_to_next;
        (*dtail)->ptr_to_next = newnode;
    }
}

void display(NODEE* tail) {
    NODEE* head = tail->ptr_to_next;
    while (head != tail) {
        printf("%d ", head->data);
        head = head->ptr_to_next;
    }
    printf("\n <-- %d", tail->data); 
}

void insertback(NODEE** dtail, int data) {
    NODEE* temp = (NODEE*)malloc(sizeof(NODEE));
    temp->data = data;
    if (*dtail == NULL) {
        printf("\nempty list\n");
        *dtail = temp;
        temp->ptr_to_next = temp;
    }
    else {
        temp->ptr_to_next = (*dtail)->ptr_to_next;
        (*dtail)->ptr_to_next = temp;
        *dtail = temp;
    }
}

void deletefront(NODEE** dtail) {
    if (*dtail == NULL) {  
        printf("\nempty list\n");
        return;
    }
    
    NODEE* head = (*dtail)->ptr_to_next;
    if (head == *dtail) { 
        *dtail = NULL;
    } else {
        (*dtail)->ptr_to_next = head->ptr_to_next; 
    }
    
    free(head);
}


int main() {
    NODEE* tail = NULL;
    int ch, data;
    while (1) {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at Back\n");
        printf("3. Delete from Front\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertfront(&tail, data);
                display(tail);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insertback(&tail, data);
                display(tail);
                break;
            case 3:
                deletefront(&tail);
                display(tail);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
