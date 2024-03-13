#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node *mergeLists(Node *list1, Node *list2)
{
    Node* mergedList = NULL;
    Node* end = NULL;
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    while(list1 != NULL && list2 != NULL){
        if(list1 -> data < list2 ->data){
            Node* newNode = createNode(list1->data);
            if (mergedList == NULL) {
                mergedList = newNode;
                end = newNode;
            } else {
                end->next = newNode;
                end = newNode;
            }
            list1 = list1->next;
        } else if (list2->data < list1->data) {
            Node* newNode = createNode(list2->data);
            if (mergedList == NULL) {
                mergedList = newNode;
                end = newNode;
            } else {
                end->next = newNode;
                end = newNode;
            }
            list2 = list2->next;
        } else {
            list1 = list1->next;
            list2 = list2->next;
        }
    }
     while(list2!= NULL){
        if (mergedList == NULL) {
                mergedList = list2;
                end = list2;
            } else {
                end->next = list2;
                end = list2;
            }
     }
      while(list1!= NULL){
        if (mergedList == NULL) {
                mergedList = list1;
                end = list1;
            } else {
                end->next = list1;
                end = list1;
            }
     }


    
    return mergedList;
}


void displayList(Node *head)
{
    Node *current = head;
    while (current)
    {
        printf("%d - ", current->data);
        current = current->next;
    }
}

// Driver code
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Node *l1=NULL, *l2=NULL, *temp=NULL;
    int num;
    if (m > 0)
    {
        scanf("%d", &num);
        l1 = createNode(num);
        temp = l1;
        for (int i = 1; i < m; i++)
        {
            scanf("%d", &num);
            temp->next = createNode(num);
            temp = temp->next;
        }
    }
    if (n > 0)
    {
        scanf("%d", &num);
        l2 = createNode(num);
        temp = l2;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &num);
            temp->next = createNode(num);
            temp = temp->next;
        }
    }

    Node *mergedList = mergeLists(l1, l2);
    displayList(mergedList);
    return 0;
}