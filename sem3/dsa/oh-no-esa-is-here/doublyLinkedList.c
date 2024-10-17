#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *ll;
  int data;
  struct node *rl;
} NODEE;

NODEE *insertFront(NODEE **head, int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  if (*head == NULL) {
    newNode->data = data;
    newNode->rl = NULL;
    (*head) = newNode;
  } else {
    newNode->rl = (*head);
    (*head)->ll = newNode;
    *head = newNode;
  }
  return *head;
}

void deleteFront(NODEE **head) {
  NODEE *dhead;
  dhead = *head;
  if (*head == NULL) {
    printf("There is nothing here to delete here!\n");
    return;
  } else {
    if (dhead->rl == NULL) {
      free(dhead);
      dhead = NULL;
      (*head)->rl = NULL;
    } else {
      (*head) = (*head)->rl;
      (*head)->ll = NULL;
      free(dhead);
      dhead = NULL;
    }
  }
}

void insertBack(NODEE **head, int data) {
  NODEE *dhead;
  dhead = *head;

  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  newNode->rl = NULL;
  newNode->ll = NULL;
  if (dhead == NULL) {
    insertFront(head, data); // or should I do it here only?
    return;
  } else {
    while (dhead->rl != NULL) {
      dhead = dhead->rl;
    }
    dhead->rl = newNode;
    newNode->ll = dhead;
  }
}

void deleteBack(NODEE **head) {
  NODEE *dhead;
  dhead = *head;
  if (dhead == NULL) {
    printf("theres nothing to delete here!\n");
    return;
  } else {
    while (dhead->rl->rl != NULL) {
      dhead = dhead->rl;
    }
    NODEE *temp = dhead;
    temp = temp->rl;
    dhead->rl = NULL;
    free(temp);
    temp = NULL;
  }
}

int main() {
  NODEE *head = NULL;
  int choice, data;
  while (1) {
    printf(
        "1. Insert Front\n2. Delete Front\n3. Insert Back\n4. Delete Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the data: ");
      scanf("%d", &data);
      head = insertFront(&head, data);
      break;
    case 2:
      deleteFront(&head);
      break;
    case 3:
      printf("Enter the data: ");
      scanf("%d", &data);
      insertBack(&head, data);
      break;
    case 4:
      deleteBack(&head);
      break;
    default:
      printf("Invalid Choice!\n");
      break;
    }
  }
  return 0;
}
