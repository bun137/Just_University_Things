#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) 
{
    int rank, size; 

    MPI_Init(&argc, &argv); // Initialize MPI

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get rank (ID) of process
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get total number of processes

    printf("Hello World from %d of %d\n", rank, size); 

    MPI_Finalize(); // Finalize MPI
    return 0;
}
