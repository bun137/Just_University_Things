// Write a program which accepts 2 integers x and y. Now use exec to execute
// another user defined program that prints the product of x and y.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int x, y;
  printf("Enter x and y: ");
  scanf("%d %d", &x, &y);
  pid_t child = fork();
  if (child == -1)
    return 1;
  if (child) {
    int status;
    waitpid(child, &status, 0);
    return 0;
  } else {
    char x_str[10], y_str[10];
    sprintf(x_str, "%d", x);
    sprintf(y_str, "%d", y);
    execl("./q3_helper", "./q3_helper", x_str, y_str, (char *)NULL);
  }
}
