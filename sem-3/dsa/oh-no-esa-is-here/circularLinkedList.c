#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *cllptr;
  int data;
} NODEE;

void insertFront(NODEE **tail, int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  if (*tail == NULL) {
    printf("ohh theres no data here!\n");
    *tail = newNode;
    newNode->cllptr = newNode;
  } else {
    newNode->cllptr = (*tail)->cllptr;
    (*tail)->cllptr = newNode;
  }
}

void deleteFront(NODEE **tail) {
  if (*tail == NULL) {
    printf("well, theres nothing here to delete!\n");
    return;
  } else {
    NODEE *start = (*tail)->cllptr;
    if (start == *tail) {
      *tail = NULL;
    } else {
      while (start->cllptr != *tail) {
        start = start->cllptr;
      }
      start->cllptr = start->cllptr->cllptr;
      free(tail);
      *tail = start;
    }
  }
}

void insertBack(NODEE **tail, int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  newNode->cllptr = NULL;
  if (*tail == NULL) {
    insertFront(tail, data);
    return;
  } else {
    // lols the first time I came to this else block I wrote a inf while loop
    // :joy:, my condition was (dtail -> cllptr != NULL) :joy:
    newNode->cllptr = (*tail)->cllptr;
    (*tail)->cllptr = newNode;
    *tail = newNode;
  }
}

void deleteBack(NODEE **tail) {
  if (*tail == NULL) {
    printf("404 node not found-\n");
    return;
  } else {
    NODEE *start;
    start = (*tail)->cllptr;
    if (start == *tail) { // you have only one node
      free(tail);
      *tail = NULL;
    } else {
      while (start->cllptr != *tail) {
        start = start->cllptr;
      }
      start->cllptr = (*tail)->cllptr;
      free(tail);
      *tail = start;
    }
  }
}

void display(NODEE *tail) {
  if (tail == NULL) {
    printf("404 node not found-\n");
    return;
  } else {
    NODEE *start = tail->cllptr;
    while (start != tail) {
      printf("%d ", start->data);
      start = start->cllptr;
    }
    printf("%d ", start->data);
  }
}

int main() {
  NODEE *tail = NULL;
  int choice, data;
  while (1) {
    printf("\n1. Insert Front\n2. Insert Back\n3. Delete Front\n4. Delete "
           "Back\n5. Display\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertFront(&tail, data);
      break;
    case 2:
      printf("Enter data to insert: ");
      scanf("%d", &data);
      insertBack(&tail, data);
      break;
    case 3:
      deleteFront(&tail);
      break;
    case 4:
      deleteBack(&tail);
      break;
    case 5:
      display(tail);
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}
