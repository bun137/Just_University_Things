#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  int pid = fork();
  if(pid>0){
    sleep(30);
    printf("In Parent process \n");
    exit(0);
  }else if(pid==0){
    printf("In Child process\n");
  }
  return 0;
}
