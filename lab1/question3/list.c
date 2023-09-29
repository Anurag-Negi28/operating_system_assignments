#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main() {
  // Get the current directory.
  char current_directory[1024];
  getcwd(current_directory, sizeof(current_directory));

  // Iterate over the files in the current directory.
  DIR *dir = opendir(current_directory);
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Print the name of the file.
    printf("%s\n", entry->d_name);
  }

  // Close the directory.
  closedir(dir);

  return 0;
}

