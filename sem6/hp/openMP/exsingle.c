#include <omp.h>
#include <stdio.h>

int main() {
  int n = 10;
  int a, b[10], i;
#pragma omp parallel shared(a, b) private(i)
  {
#pragma omp single
    {
      a = 10;
      printf("Single construct executed by thread %d\n", omp_get_thread_num());
    }

#pragma omp for
    for (i = 0; i < n; i++) {
      b[i] = a;
    }
  }

  printf("After the parallel region: \n");
  for (i = 0; i < n; i++) {
    printf("b[%d] = %d\n", i, b[i]);
  }
}
