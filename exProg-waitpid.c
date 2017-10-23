#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid1 = 0, pid2 = 0;
  int i = 3;

  pid1 = fork();

  if(pid1 != 0) {
    printf("%d\n", ++i);
    pid2 = fork();
    if(pid2 != 0) {
      waitpid(pid1, NULL, 0);
      printf("%d\n", ++i);
      waitpid(pid2, NULL, 0);
      printf("%d\n", ++i);
    }

    else {
      fork();
      printf("%d\n", ++i);
    }

    exit(0);
  }

  printf("%d\n", ++i);
}

