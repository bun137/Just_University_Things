// complete binary tree -> shape property
// parental dominance req
// TOP DOWN LEFT TO RIGHT FASHION
// bottom up heap also exists-

#include <stdio.h>

#define MAX_HEAP_SIZE 128

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifi(int arr[], int size, int index) {
  int largest = index;
  int leftChild = (2 * index + 1);
  int rightChild = (2 * index + 2);

  if (leftChild < size && arr[leftChild] > arr[largest]) {
    largest = leftChild;
  }
  if (rightChild < size && arr[rightChild] > arr[largest]) {
    largest = rightChild;
  }
  if (largest != index) {
    swap(&arr[index], &arr[largest]);
    heapifi(arr, size, largest);
  }
}

void buildingBottomUpHeap(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapifi(arr, size, i);
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
  printf("Enter the size of array: ");
  scanf("%d", &n);
  int arr[n];
  printf("halo give array elements pa \n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int size = sizeof(arr) / sizeof(arr[0]);

  printf("OG Array is :");
  printHeap(arr, size);

  buildingBottomUpHeap(arr, size);

  printf("Heap constructed with Bottom Up whatever: ");
  printHeap(arr, size);

  return 0;
}
