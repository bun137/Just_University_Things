#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 64

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int size, int index) {
  int largest = index;
  int lchild = 2 * index + 1;
  int rchild = 2 * index + 2;
  if (lchild < size && arr[largest] < arr[lchild]) {
    largest = lchild;
  }
  if (rchild < size && arr[largest] < arr[rchild]) {
    largest = rchild;
  }
  if (largest != index) {
    swap(&arr[largest], &arr[index]);
    heapify(arr, size, largest);
  }
}

void enqueue(int arr[], int *n, int data) {
  (*n)++;
  arr[*n - 1] = data;
  int i = (*n) - 1;
  while (i && arr[i / 2] < arr[i]) {
    swap(&arr[i / 2], &arr[i]);
    i = i / 2;
  }
}

int dequeue(int arr[], int *n) {
  if (*n == 0) {
    printf("no more things in the stupid queue to DEQ!\n");
    return -1;
  }
  (*n)--;
  int a = arr[0];
  arr[0] = arr[*n];
  heapify(arr, *n, 0);
  return a;
}

int main(int argc, char *argv[]) {
  int choice;
  int element;
  int arr[MAXSIZE];
  int n = 0;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enqueue(arr, &n, element);
      break;
    case 2:
      printf("Dequeued element: %d\n", dequeue(arr, &n));
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}
