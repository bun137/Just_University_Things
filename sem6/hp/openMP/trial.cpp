#include <omp.h>
#include <stdio.h>

int main() {
  omp_set_num_threads(6);
#pragma omp parallel
  {
    // printf("hii im from thread number: %d\n", omp_get_thread_num());
    int ID = omp_get_thread_num();
    printf("hello (%d)\t", ID);
    printf("starfish (%d)\t", ID);
    printf("penguinn (%d)\t", ID);
    printf("frogi (%d)\t", ID);
    printf("chickpeas (%d)\t", ID);
    printf("icecream (%d)\t", ID);
    printf("waffless (%d)\t", ID);
    printf("worldi (%d)\n", ID);
  }
}
