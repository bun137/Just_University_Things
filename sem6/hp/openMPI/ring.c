#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
  int rank, size, message = -1, tag = 11111;

  MPI_Init(NULL, NULL);                 // Initialize MPI
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Get process rank
  MPI_Comm_size(MPI_COMM_WORLD, &size); // Get number of processes

  int to = (rank + 1) % size;          // Next process in ring
  int from = (rank + size - 1) % size; // Previous process in ring

  if (rank == 0) {
    message = 42; // Initial message
    printf("Process %d sending %d to Process %d\n", rank, message, to);
    MPI_Send(&message, 1, MPI_INT, to, tag, MPI_COMM_WORLD);
    MPI_Recv(&message, 1, MPI_INT, from, tag, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("Process %d received %d from Process %d\n", rank, message, from);
  } else {
    MPI_Recv(&message, 1, MPI_INT, from, tag, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("Process %d received %d from Process %d\n", rank, message, from);
    MPI_Send(&message, 1, MPI_INT, to, tag, MPI_COMM_WORLD);
    printf("Process %d sent %d to Process %d\n", rank, message, to);
  }

  MPI_Finalize(); // Finalize MPI
  return 0;
}
