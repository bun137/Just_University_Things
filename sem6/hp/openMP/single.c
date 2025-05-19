#include <omp.h>
#include <stdio.h>

int main() {
  int i, numt, id;

#pragma omp parallel private(id) shared(numt)
  {
#pragma omp single
    // above ensures that only one thread does the below block
    {
      printf("Thread num: %d\n", omp_get_thread_num());
    }
    printf("Thread num outside: %d and id: %d\n", omp_get_thread_num(), id);
  }
}
