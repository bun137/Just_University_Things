#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* ptr_to_next;
}NODEE;

void insertion_at_req(int data,NODEE **head){
    NODEE *newnode = (NODEE*)malloc(sizeof(NODEE));
    NODEE *ohead = *head;
    newnode->data=data;
    if((*head)==NULL){
        *head=newnode;
        newnode->ptr_to_next =NULL;
        return ;
    }
    if((*head)->data > data){
        newnode->ptr_to_next = *head;
        *head=newnode;
        return;
    }
    while((*head)->ptr_to_next != NULL ){
        if((*head)->ptr_to_next->data > data){
            newnode -> ptr_to_next =(*head) ->ptr_to_next;
            (*head)->ptr_to_next = newnode;
            *head = ohead;
            return;
        }
       *head=(*head)->ptr_to_next;
    }
    (*head)->ptr_to_next=newnode;
    newnode->ptr_to_next=NULL;
    *head = ohead;
}

void deli_at_req(NODEE **head, int data){

    if((*head)== NULL){
        printf("boss, nothing here to deli");
        return ;}

    NODEE *dhead = *head;
    NODEE *slhead = *head;

    if(dhead->data == data){ // for the firsti ele
        dhead= dhead->ptr_to_next;
        free(*head);
        *head= dhead;
        return ;
    }
    while(dhead-> ptr_to_next != NULL){ // from second ele to the last ele, last ele is later
        if(dhead->ptr_to_next->data == data){
            NODEE* temp= dhead->ptr_to_next;
            dhead->ptr_to_next=dhead->ptr_to_next->ptr_to_next;
            free(temp);
            return ;
        } 
        slhead = dhead;
        dhead= dhead->ptr_to_next;     
    }
    if(dhead->data== data){
        slhead->ptr_to_next= NULL;
        free(dhead);
        return ;
    }
    printf("data not found 404");
}

void display(NODEE *head){
    while(head!= NULL){
        printf("%d ",head->data);
        head = head -> ptr_to_next;
    }
}

int main(){
    NODEE *head= NULL;
    int c;
    int data;
    while(c != 0){
        printf("\nhallo, enteri your choice -, rem '0' to exit: ");
        scanf("%d",&c);
        switch(c){
           case 1:
           scanf("%d",&data);
            insertion_at_req(data,&head);
            display(head);
            break;
        case 2:
            scanf("%d",&data);
            deli_at_req(&head,data);
            display(head);
            break;
    }
    }
    return 0;
}