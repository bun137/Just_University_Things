#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int size, int index) {
  int largest = index;
  int lchild = 2 * index + 2;
  int rchild = 2 * index + 1;

  if (lchild < size && arr[lchild] > arr[largest]) {
    largest = lchild;
  }
  if (rchild < size && arr[rchild] > arr[largest]) {
    largest = rchild;
  }
  if (largest != index) {
    swap(&arr[largest], &arr[index]);
    heapify(arr, size, largest);
  }
}

void buildHeap(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(arr, size, i);
  }
}

int main() {
  int n;
  printf("how many elements do you want to insert? ");
  scanf("%d", &n);
  int arr[n];
  printf("enter you elements now: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("\n heres the original heap elements you entered: ");
  for (int j = 0; j < n; j++) {
    printf("%d ", arr[j]);
  }
  int size = sizeof(arr) / sizeof(arr[0]);
  buildHeap(arr, size);
  printf("\nheres the heapified stuff: ");
  for (int k = 0; k < n; k++) {
    printf("%d ", arr[k]);
  }
}
