#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t p1, p2;
  int y = 0;
  p1 = fork();
  if(p1>0){
    wait(NULL);
    y = y - 1;
    printf("this is parent, pid = %d, y = %d\n", getpid(), y);
    execlp("bin/ls", "ls", NULL);
  }else if(p1 == 0){
   p2 = fork();
   if(p2>0){
     wait(NULL);
   }else if(p2 == 0){
     y = y + 1;
     printf("this is child, pid = %d, y = %d\n ppid = %d\n", getpid(), y, getppid());
     exit(0);
    }else{
      printf("fork failed\n");
    }
  }else{
    printf("fork failed\n");
  }
}
