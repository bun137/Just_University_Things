#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024       // Matrix size
#define TILE_SIZE 32 // Tile size for tiling

void matrix_multiply_tiled(double A[N][N], double B[N][N], double C[N][N]) {
  int i, j, k, ii, jj, kk;

#pragma omp parallel for collapse(2) private(i, j, k, ii, jj, kk)              \
    schedule(dynamic)
  for (ii = 0; ii < N; ii += TILE_SIZE) {
    for (jj = 0; jj < N; jj += TILE_SIZE) {
      for (kk = 0; kk < N; kk += TILE_SIZE) {
        for (i = ii; i < ii + TILE_SIZE; i++) {
          for (j = jj; j < jj + TILE_SIZE; j++) {
            double sum = 0.0;
            for (k = kk; k < kk + TILE_SIZE; k++) {
              sum += A[i][k] * B[k][j];
            }
            C[i][j] += sum;
          }
        }
      }
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
  matrix_multiply_tiled(A, B, C);
  double end_time = omp_get_wtime();

  printf("Time taken: %f seconds\n", end_time - start_time);

  return 0;
}
