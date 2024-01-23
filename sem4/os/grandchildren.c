#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t p1, p2;
  int y = 0;
  p1 = fork();
  if (p1>0){
    wait(NULL);
    y= y-1;
    printf("this is the parent process, pid = %d,y = %d\n", getpid(),  y);
    execlp("bin/ls", "ls", NULL);
  }else if(p1 == 0){
    p2 = fork();
    if(p2>0){
      wait(NULL);
    }else if(p2 ==0){
      y = y + 5;
      printf("this is the grandchild process, pid = %d,ppid = %d, y = %d\n", getpid(), getppid(), y);
      execlp("bin/ls", "ls", NULL);
      exit(0);
    }y = y + 1;
    printf("this is the child process, pid = %d,ppid = %d, y = %d\n", getpid(), getppid(), y);
    char *a[] = {NULL};
    execv("/home/shreya/Documents/Stuff/PES/sem4/os/helloWorld.exe", a);
    exit(0);
  }else{
    printf("fork failed\n");
  }
}
