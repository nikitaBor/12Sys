#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){
  printf("I am parent %d and I will FORK\n", getpid());
  int granny = getpid();
  int child = fork();
  if (getpid() == granny){//parent
    child = fork();
    int status;
    int childPID = wait(&status);
    if (status){
      printf("Parent says:'child %d just woke up and slept for %d seconds I'm done bye\n", childPID, WEXITSTATUS(status));
    }
  }

  if (!child){//don't let the ! mislead you; this means it's a child
    printf("I am a child and my pid is %d\n", getpid());
    srand(getpid());
    int timeAsleep = rand()%16+5;//5 to 21 seconds of sleep wow envy of Stuy kids
    sleep(timeAsleep); //sleeps between 5 and 20 seconds
    printf("I am child %d and I woke up\n", getpid());
    return timeAsleep;
  }
    // int f1, f2; //determines which is child
  // f1 = fork();
  // if(f1) //only forks from original parent the second time
  //   f2 = fork();

  // srand(time(NULL));
  // if(!f1 || !f2){ //if either child
  //   printf("I am a child and my pid is %d\n", getpid());
  //   int timeAsleep = 5 + (int)(random()*16);
  //   sleep(timeAsleep); //sleeps between 5 and 20 seconds
  //   printf("I am child %d and I woke up\n", getpid());
  //   return timeAsleep;
  // }
  // else{//parent
  //   int status;
  //   int childPID = wait(&status);
  //   printf("Parent says:'child %d just woke up and slept for %d seconds'\n",
	//    childPID,
	//    WEXITSTATUS(status));
  // }
}
