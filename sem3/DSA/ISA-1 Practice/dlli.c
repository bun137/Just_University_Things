#include <stdio.h>
#include <stdlib.h>

typedef struct dll_node
{
    struct dll_node *llink;
    int data;
    struct dll_node *rlink;
} NODEE;

void insertfront(NODEE **start, int data)
{
    NODEE *newnode = (NODEE *)malloc(sizeof(NODEE));
    if (*start == NULL)
    {
        (*start) = newnode;
        newnode->rlink = NULL;
        newnode->data = data;
    }
    else{
        (*start)-> llink = newnode;
        newnode -> rlink = (*start) ;
        newnode->data = data;
        *start = newnode;
    }
}

void insertend(NODEE **start, int data){
    NODEE *newnode = (NODEE *)malloc(sizeof(NODEE));
    NODEE* dstart;
    newnode -> data = data;
    newnode -> rlink = NULL;
    newnode -> llink = NULL;
    if (*start == NULL){
        printf("\nempty ddl, gonna just insert off \n");
        insertfront(start, data);
    }
    else{
        dstart = *start;
        while(dstart -> rlink != NULL){
            dstart = dstart -> rlink;
        }
        dstart -> rlink = newnode;
        newnode -> llink = dstart;
    }
}

void deletefront(NODEE**start){
    NODEE* dstart;
    dstart = *start;
    if (*start == NULL){
        printf("\n empty list, nothing here to delete\n");
        return ;
    }else{
        if(dstart -> rlink == NULL){
            free(dstart);
            *start = NULL;
            return ;
        }else{
            (*start) = (*start)-> rlink;
            free(dstart);
            dstart = NULL;
            (*start) -> llink = NULL;
        }
    }
}

void deleteback(NODEE** start){
    NODEE*dstart;
    dstart = *start;
    if (*start == NULL){
        printf("\n nothing to delete here, ta-ta bye bye\n");
        return ;
    }else{
        while(dstart -> rlink != NULL){
            dstart = dstart -> rlink;
        }
        dstart -> llink -> rlink = NULL;
        free(dstart);
        dstart = NULL;
    }
}

void delete_pos(NODEE **start, int pos){
    if (*start == NULL){
        printf("\n nothing here boss, cant delete anything-\n");
        return;
    }else{
        int i = 0;
        NODEE* dstart;
        dstart = *start;
        while(i<pos && dstart -> rlink != NULL){
            dstart = dstart -> rlink;
            i++; 
        }if(dstart -> llink == NULL){
            (*start) = dstart -> rlink;
            free(dstart);
            dstart = NULL;
            return;
        }else{
            if ( i == pos){
                if (dstart -> rlink == NULL){ // -> last element
                    dstart -> llink -> rlink = NULL;
                    dstart -> llink = NULL;
                    free(dstart);
                    dstart = NULL;
                }else{
                    dstart -> llink -> rlink = dstart -> rlink;
                    dstart -> rlink -> llink = dstart -> llink;
                    dstart -> llink = NULL;
                    dstart -> rlink = NULL;
                    free(dstart);
                    dstart = NULL;
                }
            }
            else{
                    printf("\n boss check you position, invalid pos! \n");
            }
        }
    }
}

void insert_pos(NODEE** start, int pos, int data){
   
    if (*start == NULL || pos == 0){
        insertfront(start, data);
    }else{
         NODEE*newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode -> data = data;
    newnode -> rlink= NULL;
    newnode -> llink= NULL;
        int i = 0;
        NODEE* dstart;
        dstart = *start;
        while (i< pos && dstart -> rlink != NULL){
            dstart = dstart -> rlink;
            i++;
        }
        if(dstart-> llink == NULL){
            (*start) -> llink = newnode;
            newnode -> rlink  = *start;
            *start = newnode;
        }
        else {
            if( i == pos){
            dstart -> llink -> rlink = newnode;
            newnode -> rlink = dstart;
            newnode -> llink = dstart -> llink;
            dstart -> llink = newnode;
            }
            else{
                if(pos == i+1){
                    dstart -> rlink = newnode;
                    newnode -> llink = dstart;
                }else{
                    printf("\n idk what pos you gave pa, pls check!\n");
                }
            }
        }
    } 
}

void display(NODEE* head){
    while(head -> rlink != NULL){
        printf("%d ", head -> data);
        head = head -> rlink;
    }
    printf("%d\n", head -> data);
}


int main() {
    NODEE *start;
    start = NULL;
    int choice, data, position;
    
    do {
        printf("\n--- MENU ---");
        printf("\n1. Insert at front");
        printf("\n2. Insert at end");
        printf("\n3. Insert at position");
        printf("\n4. Delete from front");
        printf("\n5. Delete from end");
        printf("\n6. Delete from position");
        printf("\n7. Exit");
        printf("\ndisplay?\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertfront(&start, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertend(&start, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insert_pos(&start, position, data);
                break;
            case 4:
                deletefront(&start);
                break;
            case 5:
                deleteback(&start);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete_pos(&start, position);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            case 8:
                display(start);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
