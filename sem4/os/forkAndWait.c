#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
  pid_t p1;
  int y = 0;
  p1 = fork();
  if(p1>0){
    wait (NULL);
    y = y - 1;
    printf("this is parent, pid = %d, y = %d\n", getpid(), y);
    wait(NULL);
  }else if(p1 == 0){
    y = y + 1;
    printf("this is child, pid = %d, y = %d\n ppid = %d\n", getpid(), y, getppid());
    exit(0);
  }else{
    printf("fork failed\n");
  }
}
