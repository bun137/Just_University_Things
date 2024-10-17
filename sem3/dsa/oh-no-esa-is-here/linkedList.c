#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *ptr;
} NODEE;

NODEE *insertFront(NODEE **head, int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  newNode->ptr = *head;
  *head = newNode;
  return *head;
}

NODEE *deleteFront(NODEE **head) {
  NODEE *dhead = *head;
  if (dhead == NULL) {
    printf("theres nothing here to deleeee!\n");
    return *head;
  }
  *head = (*head)->ptr;
  free(dhead);
  dhead = NULL;
  return *head;
}
void deleteBack(NODEE **head, int data) {
  if (*head == NULL) {
    printf("There is no node here to delete\n");
  } else {
    if ((*head)->ptr == NULL) {
      NODEE *dhead = *head;
      dhead = dhead->ptr;
      free(dhead);
      dhead = NULL;
      *head = NULL;
    } else {
      NODEE *dhead = *head;
      while ((dhead)->ptr->ptr != NULL) {
        (dhead) = (dhead)->ptr;
      }
      NODEE *temp = dhead;
      temp = temp->ptr;
      free(temp);
      temp = NULL;
      dhead->ptr = NULL;
    }
  }
}

void insertBack(NODEE **head, int data) {
  NODEE *dhead = *head;
  if (dhead == NULL) {
    insertFront(head, data);
    return;
  } else {
    while (dhead->ptr != NULL) {
      dhead = dhead->ptr;
    }
    NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
    newNode->data = data;
    newNode->ptr = NULL;
    dhead->ptr = newNode;
  }
}

void printList(NODEE *head) {
  NODEE *dhead = head;
  while (dhead != NULL) {
    printf("%d ", dhead->data);
    dhead = dhead->ptr;
  }
  printf("\n");
}

int main() {
  NODEE *head = NULL;
  int data, choice;
  while (1) {
    printf("1. insertFront\n2. deleteFront\n3. insertBack\n4. deleteBack\n5. "
           "printList\n6. exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      head = insertFront(&head, data);
      break;
    case 2:
      head = deleteFront(&head);
      break;
    case 3:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertBack(&head, data);
      break;
    case 4:
      deleteBack(&head, data);
      break;
    case 5:
      printList(head);
      break;
    case 6:
      return 0;
    default:
      printf("Enter a valid choice\n");
      break;
    }
  }
  return 0;
}
