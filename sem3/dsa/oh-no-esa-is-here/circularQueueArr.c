#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 2

typedef struct queueee {
  int arr[MAX_SIZE];
  int f;
  int b;
} Q_t;

int isKhali(Q_t *que) { return (que->f == -1 && que->b == -1); }

int isPura(Q_t *que) { return ((que->b + 1) % MAX_SIZE == que->f); }

void enqueue(Q_t *que, int data) {
  if (isPura(que)) {
    printf("your q is full!\n");
    return;
  } else {
    if (isKhali(que)) {
      que->f += 1;
      que->b += 1;
    } else {
      if (que->b == MAX_SIZE - 1) {
        que->b = 0;
      } else {
        que->b += 1;
      }
    }
    que->arr[que->b] = data;
    printf("successfullyy insertedd!\n");
  }
}

int dequeue(Q_t *que) {
  if (isKhali(que)) {
    printf("array is empty ugh, nothing to dq\n");
    return -1;
  } else {
    int ele = que->arr[que->f];
    if (que->f == que->b) {
      que->f = -1;
      que->b = -1;
    } else if (que->f == MAX_SIZE - 1) {
      que->f = 0;
    } else {
      que->f += 1;
    }
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
