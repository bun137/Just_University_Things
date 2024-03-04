#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  int fd[2];
  pipe(fd);
  int id = fork();
  if (id == 0) {
    close(fd[1]);
    char msg[100];
    read(fd[0], msg, sizeof(msg)); // to read the input string from the terminal
    close(fd[0]);
    int start = 0;
    int end = strlen(msg) - 1;
    while (start < end) {
      char temp = msg[start];
      msg[start] = msg[end];
      msg[end] = temp;
      start++;
      end--;
    }
    printf("Reversed string: %s\n", msg);
  } else {
    close(fd[0]);
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    write(fd[1], input, sizeof(input));
    close(fd[1]);
  }
  return 0;
}
