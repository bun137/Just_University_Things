#include <omp.h>
#include <stdio.h>

int main() {
  int i, numt, id;

#pragma omp parallel private(id) shared(numt)
  {
    id = omp_get_thread_num();
    if (id == 0) {
      numt = omp_get_num_threads();
    }
    for (i = 0; i < 100; i++)
      ;
    printf("Output from thread %d of %d \n\n", id, numt);
  }
}
