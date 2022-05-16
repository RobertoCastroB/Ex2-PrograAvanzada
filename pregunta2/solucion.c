#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

FILE *f;

void sigusr1_handler(int s){
    printf("Soy el proceso A y Mi PID es: [%d]\n",getpid());
}

int main () {
  char buffer[BUFSIZ];
  int n;
  f = fopen("proceso.pid","w+");
  if (!fork()){
    fprintf(f, "%d", getpid());
    fflush(f);
    signal(SIGUSR1, sigusr1_handler);
    if(!fork()){
      if(!fork()){
        printf("Soy el proceso C y mi PID es: [%d] y el de mi padre: [%d]\n", getpid(), getppid());
        sleep(3);
        f = fopen("proceso.pid","rw");
        fscanf(f, "%d", &n);
        kill((pid_t)n,SIGUSR1);
      }
      wait(0);
    }
    wait(0);
  }
}
