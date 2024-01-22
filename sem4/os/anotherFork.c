#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t p1;
  int y = 0;
  p1 = fork();
  if(p1>0){
    y = y - 1;
    printf("this is parent, pid = %d, y = %d\n", getpid(), y);
  }else if(p1 == 0){
    y = y + 1;
    printf("this is child, pid = %d, y = %d\n", getpid(), y);
  }else{
    printf("fork failed\n");
  }
}
