#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main() {
  // Get the current process ID.
  int pid = getpid();
  printf("My pid is: %d\n", pid);

  // Create a child process.
  int child_pid = fork();

  // Check if the child process was created successfully.
  if (child_pid == -1) {
    printf("Error creating child process.\n");
    return 1;
  }

  // The child process will execute this code.
  if (child_pid == 0) {
    printf("I am the child process, my pid is: %d\n", getpid());
    exit(0);
  }

  // The parent process will execute this code.
  else {
    printf("I am the parent process, my child pid is: %d\n", child_pid);
  }

  return 0;
}
