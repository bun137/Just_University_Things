#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int nthreads, tid, procs, maxt, inpar, dynamic, nested;

#pragma omp parallel private(nthreads, tid)
  {
    tid = omp_get_thread_num();

    if (tid == 0) {
      printf("\nThread %d getting environment information:\n\n", tid);
      procs = omp_get_num_procs();
      nthreads = omp_get_num_threads();
      maxt = omp_get_max_threads();
      inpar = omp_in_parallel();
      dynamic = omp_get_dynamic();
      nested = omp_get_max_active_levels();

      printf("\tNumber of Processors: %d\n", procs);
      printf("\tNumber of threads: %d\n", nthreads);
      printf("\tMax Threads: %d\n", maxt);
      printf("\tIn Parallel: %d\n", inpar);
      printf("\tDynamic Threads enabled: %d\n", dynamic);
      printf("\tNested parallelism supported: %d\n\n", nested);
    }
  }
}
