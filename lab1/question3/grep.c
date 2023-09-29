#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments are provided.
  if (argc != 3) {
    printf("Usage: grep pattern file\n");
    return 1;
  }

  // Get the pattern to search for.
  char *pattern = argv[1];

  // Get the file to search.
  char *file = argv[2];

  // Open the file.
  FILE *fp = fopen(file, "r");

  // Iterate over the lines in the file.
  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    // Check if the line contains the pattern.
    if (strstr(line, pattern)) {
      printf("%s", line);
    }
  }

  // Close the file.
  fclose(fp);

  return 0;
}

