#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  int pid = fork();
  if(pid>0){
    printf("Parent process, pid = %d\n", getpid());
    exit(0);
  }else if(pid==0){
    sleep(30);
    printf("Child process, pid = %d\n parent proccess pid = %d\n", getpid(), getppid());
  }
  return 0;
}
