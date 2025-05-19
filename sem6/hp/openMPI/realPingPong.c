#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv) {
  const int PING_PONG_LIMIT = 10;
  MPI_Init(NULL, NULL);
  int w_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &w_rank);
  int w_size;
  MPI_Comm_size(MPI_COMM_WORLD, &w_size);
  // We are assuming 2 processes for this task
  if (w_size != 2) {
    fprintf(stderr, "World size must be two for %s\n", argv[0]);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  int ping_pong_count = 0;
  int p_rank = (w_rank + 1) % 2;
  while (ping_pong_count < PING_PONG_LIMIT) {
    if (w_rank == ping_pong_count % 2) {
      // Increment the ping pong count before you send it
      ping_pong_count++;
      MPI_Send(&ping_pong_count, 1, MPI_INT, p_rank, 0, MPI_COMM_WORLD);
      printf("%d sent and incremented ping_pong_count "
             "%d to %d\n",
             w_rank, ping_pong_count, p_rank);
    } else {
      MPI_Recv(&ping_pong_count, 1, MPI_INT, p_rank, 0, MPI_COMM_WORLD,
               MPI_STATUS_IGNORE);
      printf("%d received ping_pong_count %d from %d\n", w_rank,
             ping_pong_count, p_rank);
    }
  }
  MPI_Finalize();
}
