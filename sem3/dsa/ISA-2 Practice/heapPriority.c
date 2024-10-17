#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifi(int arr[], int index) {
  int daddy = (index - 1) / 2;
  if (daddy >= 0 && arr[daddy] < arr[index]) {
    swap(&arr[index], &arr[daddy]);
    heapifi(arr, daddy);
  }
}
void insert(int *arr[], int key, int *n) {
  int i = ((*n)++) - 1;
  *arr[i] = key;
  while (i && arr[i / 2] < arr[i]) {
    swap(arr[i / 2], arr[i]);
    i = i / 2;
  }
}
void siftFunc(int arr[], int i) {
  while (i && arr[i / 2] < arr[i]) {
    swap(&arr[i / 2], &arr[i]);
    i = i / 2;
  }
}
void delete(int *arr, int *n) {
  arr[0] = arr[*n - 1];
  (*n)--;
  heapifi(arr, *n);
}

void enq(int arr[], int key, int *n) {
  (*n)++;
  arr[*n - 1] = key;
  siftFunc(arr, *n - 1);
}

int deq(int arr[], int *n) {
  if (*n == 0) {
    return -1;
  }
  int a = arr[0];
  arr[0] = arr[*n - 1];
  (*n)--;
  heapifi(arr, *n);
  return (a);
}

void buildHeapTopDown(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    heapifi(arr, i);
  }
}

void printHeap(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main(int argc, char *argv[]) {
  int choice;
  int element;
  int arr[64];
  int n = 0;
  while (1) {
    printf("1. Enqueue\n2. Dequeue\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enq(arr, element, &n);
      break;
    case 2:
      printf("Dequeued element: %d\n", deq(arr, &n));
      break;
    case 0:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
  return EXIT_SUCCESS;
}
// int main(int argc, char *argv[]) {
//   int n;
//   printf("hey whats the size of your array? ");
//   scanf("%d", &n);
//   int arr[n];
//   printf("hmm noice so what do you want you're ele's to bee?");
//   for (int i = 0; i < n; i++) {
//     scanf("%d", &arr[i]);
//   }
//   int size = sizeof(arr) / sizeof(arr[0]);
//   printf("here your OG array: ");
//   printHeap(arr, size);
//
//   printf("\nso here the actual heappp: ");
//   buildHeapTopDown(arr, size);
//   printHeap(arr, size);
//   printf("enter the value of key: ");
//   int key;
//   scanf("%d", &key);
//   enq(arr, key, );
//   return 0;
// }
