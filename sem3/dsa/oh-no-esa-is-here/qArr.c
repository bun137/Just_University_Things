#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 64

typedef struct queueee {
  int arr[MAX_SIZE];
  int f;
  int b;
} Q_t;

void enqueue(Q_t *que, int data) {
  if (que->b == MAX_SIZE - 1) {
    printf("haha sucker no more space in the queuee! bye exiting...\n");
    return;
  } else {
    que->b += 1;
    if (que->f == -1) {
      que->f += 1;
    }
    que->arr[que->b] = data;
  }
}

int dequeue(Q_t *que) {
  if (que->f == -1 && que->b == -1) {
    printf("theres nothing here in your stupid arr! bye bye! \n");
    return -1;
  } else {
    int ele = que->arr[que->f];
    if (que->f == que->b) {
      que->f = -1;
      que->b = -1;
      return ele;
    }
    que->f += 1;
    return ele;
  }
}

int main(int argc, char *argv[]) {
  Q_t que;
  int choice;
  int element;
  que.f = -1;
  que.b = -1;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enqueue(&que, element);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(&que));
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}
