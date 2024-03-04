#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  // make 2 process which run same
  // program after this instruction
  pid_t p = fork();
  if (p < 0) {
    perror("fork fail");
    return 0;
  }
  printf("Hello World!,process_id(pid)=%d\n", getpid());
  return 0;
}

// to run this code:
// cc -static fork.c
// cc -static fork.c -o fork
// ./fork
// cc fork.c -o fork1
// ./fork1
