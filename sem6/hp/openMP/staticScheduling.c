#include <omp.h>
#include <stdio.h>
#define N 12

int main() {
  int i;
  double start_time, end_time;
  start_time = omp_get_wtime();

  #pragma omp parallel for schedule(static, 3)
  for (i = 0; i < N; i++) {
    printf("Thread num: %d processing iteration %d\n", omp_get_thread_num(), i);
  }

  end_time = omp_get_wtime();

  printf("\nTotal execution time: %f seconds\n", end_time - start_time);

  return 0;
}
