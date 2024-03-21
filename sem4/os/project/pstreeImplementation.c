#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_tree(int pid, int level, int is_last) {
  char path[256];
  snprintf(path, sizeof(path), "/proc/%d/status", pid);
  FILE *file = fopen(path, "r");
  if (!file)
    return;

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    if (strncmp(line, "Name:", 5) == 0) {
      printf("%*s├── %s", level * 4, "", line + 6);
    }
  }
  fclose(file);

  snprintf(path, sizeof(path), "/proc/%d/task/%d/children", pid, pid);
  file = fopen(path, "r");
  if (!file)
    return;

  int child_pid;
  int is_first_child = 1;
  while (fgets(line, sizeof(line), file)) {
    child_pid = atoi(line);
    if (is_first_child) {
      printf("\n%*s│", (level + 1) * 4, "");
      is_first_child = 0;
    } else {
      printf("%*s│", (level + 1) * 4, "");
    }
    print_tree(child_pid, level + 1, is_first_child);
  }
  fclose(file);

  if (!is_last) {
    printf("\n%*s└── ", level * 4, "");
  } else {
    printf("\n%*s└── ", level * 4, "");
  }
}

int main() {
  DIR *dir = opendir("/proc");
  if (!dir) {
    perror("opendir");
    return 1;
  }

  struct dirent *entry;
  int is_last = 1;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_DIR) {
      int pid = atoi(entry->d_name);
      if (pid > 0) {
        print_tree(pid, 0, is_last);
        is_last = 0;
      }
    }
  }

  closedir(dir);
  return 0;
}
