#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* ptr_to_next;
}NODEE;

void insertionfront(NODEE **head, int data){
    NODEE *newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode ->data = data;
    newnode -> ptr_to_next = *head; 
    *head = newnode;
}

void deletefront(NODEE **head){
    NODEE *p=*head;
    *head= (*head)->ptr_to_next;
    free(p);
    p = NULL;
}

void insertion_at_pos(NODEE **head, int data, int pos){

    if(*head == NULL){
        insertionfront(head, data);
        return;
    }
    else{
        NODEE *newnode = (NODEE*)malloc(sizeof(NODEE));
        newnode -> data = data;
        NODEE* dummyhead = *head;
        int i=1;
        for(i;dummyhead -> ptr_to_next != NULL ;i++){
            if(i==pos-1){
                newnode ->ptr_to_next= dummyhead->ptr_to_next;
                dummyhead->ptr_to_next= newnode;
                return;
            }
        }
        if(dummyhead->ptr_to_next== NULL){
            printf("you've reached the end: %d", i);
            dummyhead->ptr_to_next=newnode;
            newnode->ptr_to_next= NULL;
        }
    }
}

void display(NODEE *head) {
    NODEE *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->ptr_to_next;
    }
    printf("\n");
}



int main() {
    NODEE *head = NULL;
    int data, pos;

    printf("Enter data to be inserted: ");
    scanf("%d", &data);

    printf("Enter the position: ");
    scanf("%d", &pos);

    insertionfront(&head, 2);
    insertionfront(&head, 20);
    insertionfront(&head, data);

    printf("after ini insertions: ");
    display(head);
    deletefront(&head);
    printf("after deli front element: ");
    display(head);
    insertion_at_pos(&head, data, pos);
    printf("after inser_at_pos %d: ", pos);
    display(head);

 
    while (head != NULL) {
        NODEE *temp = head;
        head = head->ptr_to_next;
        free(temp);
    }

    return 0;
}
