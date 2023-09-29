#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
  // Get the system information.
  struct sysinfo si;
  sysinfo(&si);

  // Print the free memory.
  printf("Free memory: %lu\n", si.totalram);

  return 0;
}

