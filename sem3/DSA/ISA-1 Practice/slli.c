#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *ptr_to_next;
} NODEE;

void insertionfront(NODEE **head, int data) {
  NODEE *newnode = (NODEE *)malloc(sizeof(NODEE));
  newnode->data = data;
  newnode->ptr_to_next = *head;
  *head = newnode;
}

void deletefront(NODEE **head) {
  NODEE *dhead = *head;
  *head = (*head)->ptr_to_next;
  free(dhead);
  dhead = NULL;
}

void insertback(NODEE **head, int data) {
  NODEE *dhead = *head;
  if (dhead == NULL) {
    insertionfront(head, data);
  } else {
    while (dhead->ptr_to_next != NULL) {
      dhead = dhead->ptr_to_next;
    }
    NODEE *newnode = (NODEE *)malloc(sizeof(NODEE));
    newnode->data = data;
    dhead->ptr_to_next = newnode;
    newnode->ptr_to_next = NULL;
  }
}

void deleteback(NODEE **head) {
  NODEE *dhead = *head;
  if (dhead == NULL) {
    printf("nothing to delete!");
    return;
  } else if (dhead->ptr_to_next == NULL) {
    free(dhead);
    *head = NULL;
  } else {
    while (dhead->ptr_to_next->ptr_to_next != NULL) {
      dhead = dhead->ptr_to_next;
    }
    NODEE *temp = dhead;
    temp = temp->ptr_to_next;
    dhead->ptr_to_next = NULL;
    free(temp);
  }
}

void insertion_pos(int data, NODEE **head) {
  int pos;
  printf("\n heyy, at which position do you want to insert the data? : ");
  scanf("%d", &pos);
  if (*head == NULL || pos == 1) {
    insertionfront(head, data);
  } else {
    NODEE *newnode = (NODEE *)malloc(sizeof(NODEE));
    newnode->data = data;
    NODEE *dhead = *head;
    int i = 1;
    for (i; dhead != NULL; i++) {
      if (i == pos - 1) {
        newnode->ptr_to_next = dhead->ptr_to_next;
        dhead->ptr_to_next = newnode;
        return;
      }
      if (dhead->ptr_to_next == NULL) {
        printf(
            "\n you have reached the end of the sll, doesnt matter if i == pos "
            "+ 1, I'll still insert you at the end of the list, also i = %d \n",
            i);
        dhead->ptr_to_next =
            newnode; // one sec I could have just used insertback function bruhh
        newnode->ptr_to_next = NULL;
        return;
      }
      dhead = dhead->ptr_to_next;
    }
  }
}

void deletion_pos(NODEE **head) {
  int pos;
  printf(
      "\n heyy, so umm which position do you want to delete the node at? : ");
  scanf("%d", &pos);

  if (*head == NULL || pos == 1) {
    deletefront(head);
  } else {
    NODEE *dhead = *head;
    int i = 1;
    for (i; dhead->ptr_to_next != NULL; i++) {
      if (i == pos - 1) {
        NODEE *temp = dhead;
        dhead->ptr_to_next = dhead->ptr_to_next->ptr_to_next;
        temp->ptr_to_next->ptr_to_next = NULL;
        free(temp);
        temp = NULL;
      }
      if (dhead->ptr_to_next == NULL) {
        printf("\n you have reached the end of the list ");
      }
    }
  }
}

void display(NODEE *head) {
  while (head->ptr_to_next != NULL) {
    printf("%d ", head->data);
    head = head->ptr_to_next;
  }
  printf("%d\n", head->data);
}

int main() {
  NODEE *head = NULL;
  int choice, data;

  do {
    // display menu options
    printf("\nMenu\n");
    printf("1. Insert at the beginning\n");
    printf("2. Delete from the beginning\n");
    printf("3. Insert at the end\n");
    printf("4. Delete from the end\n");
    printf("5. Insert at a specific position\n");
    printf("6. Delete from a specific position\n");
    printf("7. Display the list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertionfront(&head, data);
      break;

    case 2:
      deletefront(&head);
      break;

    case 3:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertback(&head, data);
      break;

    case 4:
      deleteback(&head);
      break;

    case 5:
      printf("Enter the data to insert: ");
      scanf("%d", &data);
      insertion_pos(data, &head);
      break;

    case 6:
      deletion_pos(&head);
      break;

    case 7:
      display(head);
      break;

    case 8:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice! Please try again.\n");
    }
  } while (choice != 8);

  return 0;
}
