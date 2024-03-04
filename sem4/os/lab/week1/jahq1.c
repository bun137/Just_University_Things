#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t p1;
  p1 = fork();
  if (p1 > 0) {
    wait(NULL);

  } else if (p1 == 0) {
    // y=y+1;
    printf("This is child process Id = %d", getpid());
    execlp("/usr/bin/ps", "ps", NULL);
  } else {
    printf("fork creation failed");
  }
}
