// Create a global array with values [1,6,2,4,5,8,9,0]. Sort the same within the
// child process and display the values in the parent process.
// Are the displayed values in sorted order? If not,why?

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int arr[] = {1, 6, 2, 4, 5, 8, 9, 0};

void sort_array() {
  int n = sizeof(arr) / sizeof(arr[0]);
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void display_array() {
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    fprintf(stderr, "Failed to fork.\n");
    return 1;
  }
  if (pid == 0) {
    sort_array();
    _exit(0);
  } else {
    wait(NULL);
    display_array();
  }
  return 0;
}
