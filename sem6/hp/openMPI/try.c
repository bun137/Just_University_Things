#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv); // Initialize MPI

  int world_rank;
  int world_size;

  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); // Get the rank of the process
  MPI_Comm_size(MPI_COMM_WORLD,
                &world_size); // Get the total number of processes

  printf("Hello world from process %d out of %d\n", world_rank, world_size);

  MPI_Finalize(); // Finalize MPI
  return 0;
}
