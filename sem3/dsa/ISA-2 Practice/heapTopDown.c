// top down heappp!!

#include <stdio.h>

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
  int n;
  printf("hey whats the size of your array? ");
  scanf("%d", &n);
  int arr[n];
  printf("hmm noice so what do you want you ele's to bee?");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("here your OG array: ");
  printHeap(arr, size);

  printf("\nso here the actual heappp: ");
  buildHeapTopDown(arr, size);
  printHeap(arr, size);
  return 0;
}
