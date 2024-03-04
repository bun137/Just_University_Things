// Question 1
// Write a program to create a child process which lists all the executing user
// processes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t child = fork();
  if (child == -1)
    return 1;
  if (child) {
    int status;
    waitpid(child, &status, 0);
    return 0;
  } else {
    execl("/usr/bin/ps", "/usr/bin/ps", (char *)NULL);
  }
}
