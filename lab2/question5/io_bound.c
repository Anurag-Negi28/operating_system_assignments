#include <stdio.h>
#include <stdlib.h>

int main() {
  // Read a file line by line.
  FILE *fp = fopen("file.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    // Do something with the line.
    printf("%s\n", line);
  }

  fclose(fp);

  return 0;
}

