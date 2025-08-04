#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main() {
  int pid = fork();
  
  if (pid == 0) {
    execlp("ls", "-a", "-l", NULL);
  } else {
    int wStatus;
    waitpid(pid, &wStatus, 0);
    if (WIFEXITED(wStatus)) {
      printf("child exited normally\n");
    } else {
      printf("abnormal exit\n");
    }
  }
}

