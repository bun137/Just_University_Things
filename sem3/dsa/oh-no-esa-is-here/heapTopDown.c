#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int size, int index) {
  int parent = (index - 1) / 2;
  if (parent < size && arr[index] > arr[parent]) {
    swap(&arr[index], &arr[parent]);
    heapify(arr, size, parent);
  }
}

void buildTopDown(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    heapify(arr, size, i);
  }
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main(int argc, char *argv[]) {
  int n;
  printf("hey whats the size of your array? ");
  scanf("%d", &n);
  int arr[n];
  printf("hmm noice so what do you want you ele's to bee? ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("here your OG array: ");
  display(arr, size);

  printf("\nso here the actual heappp: ");
  buildTopDown(arr, size);
  display(arr, size);

  return EXIT_SUCCESS;
}
