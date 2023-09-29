#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Open the /proc/stat file.
  int fd = open("/proc/stat", O_RDONLY);
  if (fd == -1) {
    printf("Error opening /proc/stat file.\n");
    return 1;
  }

  // Read the first line of the file.
  char line[1024];
  int bytes_read = read(fd, line, sizeof(line));
  if (bytes_read == -1) {
    printf("Error reading /proc/stat file.\n");
    return 1;
  }

  // Close the file.
  close(fd);

  // Find the process with the highest CPU usage.
  int max_cpu_usage = 0;
  int pid = 0;
  char *token;
  char *delim = " ";
  token = strtok(line, delim);
  while (token != NULL) {
    int cpu_usage = atoi(token);
    if (cpu_usage > max_cpu_usage) {
      max_cpu_usage = cpu_usage;
      pid = atoi(token + 3);
    }
    token = strtok(NULL, delim);
  }

  // Print the process ID and CPU usage.
  printf("Process ID: %d\nCPU usage: %d%%\n", pid, max_cpu_usage);

  return 0;
}

