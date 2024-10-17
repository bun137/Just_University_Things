#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    struct Node *rlink;
    struct Node *llink;
}NODEE;

NODEE *createNode(char data)
{
    NODEE *newnode = (NODEE*)malloc(sizeof(NODEE));
    newnode->rlink = NULL;
    newnode->llink = NULL;
    newnode->data = data;
    return newnode;

}

void insertAtEnd(NODEE **head, char data)
{
    
    NODEE* temp = createNode(data);
    if (*head == NULL) {
        *head = temp;
        temp -> rlink = temp;  
        temp -> llink = temp;
    }
    else {
        temp->rlink = (*head);
        temp->llink = (*head)->llink;
        (*head)->llink->rlink = temp;
        (*head)->llink = temp;
    }
}

     
void printReverse(NODEE *head)
{
    if (head == NULL)
        return;

    NODEE *current = head->llink;
    do
    {
        printf("%c", current->data);
        current = current->llink;
    } while (current != head->llink);
}
    
int isVowel(char c) {
    c = tolower(c); 
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}




void removeVowels(NODEE **head)
{

    if(*head == NULL){
        return;
    }


    NODEE *dhead = *head;

    do {
        if (isVowel(dhead->data)) {           
            NODEE *todel = dhead;
            dhead = dhead->rlink;
            todel->llink->rlink = todel->rlink;
            todel->rlink->llink = todel->llink;
            free(todel);
        }
        else {
            dhead = dhead->rlink;
        }
    } while (dhead != *head);
}


// Driver code
int main()
{
    int N;
    char data;
    scanf("%d", &N);
    getchar();
    
    struct Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        scanf(" %c", &data);
        insertAtEnd(&head, data);
    }

    removeVowels(&head);
    printReverse(head);
    return 0;
}