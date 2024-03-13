#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  pid_t pid;
  int i;
  char cmd[10];
  pid = fork();
  if (pid == 0) {
    while (i) {
      printf("Enter the command\n");
      scanf("%s", cmd);
      printf("Here is the output of the command\n");
      system(cmd);
      printf("\nenter 1-> continue\n0->quit\n");
      scanf("%d", &i);
    }
  }
  wait(&pid);
  printf("Child process is complete\n");
}
