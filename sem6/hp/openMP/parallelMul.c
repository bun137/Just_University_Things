#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int main() {
  int a[SIZE][SIZE];
  int b[SIZE][SIZE];
  int result[SIZE][SIZE] = {0}; // Initialize result to zero
  
  // Enable nested parallelism
  omp_set_nested(1);
  
  // Initialize matrices
  #pragma omp parallel for
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      a[i][j] = i + j;
      b[i][j] = i - j;
    }
  }
  
  // Matrix multiplication
  #pragma omp parallel for
  for (int i = 0; i < SIZE; i++) {
    printf("Thread num: %d processing row %d\n", omp_get_thread_num(), i);
    
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  
  return 0;
}
