#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Declare the variables outside of the while loop.
  int pid;
  int max_memory_share = 0;

  // Open the /proc/meminfo file.
  int fd = open("/proc/meminfo", O_RDONLY);
  if (fd == -1) {
    printf("Error opening /proc/meminfo file.\n");
    return 1;
  }

  // Read the file.
  char line[1024];
  int bytes_read;
  while ((bytes_read = read(fd, line, sizeof(line))) > 0) {
    // Find the process with the maximum memory share.
    char *token;
    char *delim = ":";
    token = strtok(line, delim);
    while (token != NULL) {
      if (strncmp(token, "VmRSS:", 6) == 0) {
        int memory_share = atoi(token + 6);
        if (memory_share > max_memory_share) {
          max_memory_share = memory_share;
          pid = atoi(token + 10);
        }
      }
      token = strtok(NULL, delim);
    }
  }

  // Close the file.
  close(fd);

  // Print the process ID and memory share.
  printf("Process ID: %d\nMemory share: %d%%\n", pid, max_memory_share);

  return 0;
}

