#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024 // Matrix size

void matrix_multiply(double A[N][N], double B[N][N], double C[N][N]) {
#pragma omp parallel for collapse(2) schedule(dynamic)
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      double sum = 0.0;
      for (int k = 0; k < N; k++) {
        sum += A[i][k] * B[k][j];
      }
      C[i][j] = sum;
    }
  }
}

int main() {
  static double A[N][N], B[N][N], C[N][N] = {0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = (double)(rand() % 100) / 100.0;
      B[i][j] = (double)(rand() % 100) / 100.0;
    }
  }

  double start_time = omp_get_wtime();
  matrix_multiply(A, B, C);
  double end_time = omp_get_wtime();

  printf("Time taken: %f seconds\n", end_time - start_time);

  return 0;
}
