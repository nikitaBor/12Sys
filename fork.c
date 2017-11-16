#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
  printf("I am parent and I will FORK\n");
  int f1, f2; //determines which is child
  f1 = fork();
  if(f1) //only forks from original parent the second time
    f2 = fork();

  srand(time(NULL));
  if(!f1 || !f2){ //if either child
    printf("I am a child and my pid is %d\n", getpid());
    int timeAsleep = 5 + (int)(random()*16);
    sleep(timeAsleep); //sleeps between 5 and 20 seconds
    printf("I am child %d and I woke up\n", getpid());
    return timeAsleep;
  }
  else{
    int status;
    int childPID = wait(&status);
    printf("Parent says:'child %d just woke up and slept for %d seconds'\n",
	   childPID,
	   WEXITSTATUS(status));
  }
  return 0;
}
