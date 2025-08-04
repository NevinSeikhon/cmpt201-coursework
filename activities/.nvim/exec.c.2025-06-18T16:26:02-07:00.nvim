#include <unistd.h>
#include <stdio.h>
int main() {
  int pid = fork();
  if (pid == 0) {
    execlp("ls", "-a", "-l", "-h", NULL);
  } else {
    execlp("ls", "-a", NULL);
  }
  printf("%d\n", getpid());
}
