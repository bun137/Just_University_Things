#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define structures for metadata and file system elements
typedef struct {
    char name[100];
    int size;
    time_t creation_date;
    time_t modification_date;
} Metadata;

typedef struct {
    char name[100];
    int is_directory;
    Metadata metadata;
} FileSystemElement;

// Function prototypes
void createFile(char *name, int size);
void createDirectory(char *name);
void printMetadata(char *path);
void resolvePath(char *path);

// Global variables
FileSystemElement fileSystem[100];
int fileSystemSize = 0;
char currentPath[100] = "/home/shreya/Documents/Stuff/PES/SEM-3/DDCOLAB/WEEK 5";

int main() {
    createDirectory("Work");
    createFile("report.docx", 1024);

    char relativePath[] = "../../WEEK5/DDCOLAB5_PES2UG22CS209_GURRAM_SHREYA.docx.pdf";
    char absolutePath[200];

    printf("Enter the relative path: %s\n", relativePath);

    // Resolve relative path to absolute path
    strcpy(absolutePath, currentPath);
    resolvePath(relativePath);
    strcat(absolutePath, "/");
    strcat(absolutePath, relativePath);

    // Access metadata using the absolute path
    printMetadata(absolutePath);

    return 0;
}

void createFile(char *name, int size) {
    strcpy(fileSystem[fileSystemSize].name, name);
    fileSystem[fileSystemSize].is_directory = 0;
    fileSystem[fileSystemSize].metadata.size = size;
    fileSystem[fileSystemSize].metadata.creation_date = time(NULL);
    fileSystem[fileSystemSize].metadata.modification_date = time(NULL);
    fileSystemSize++;
}

void createDirectory(char *name) {
    strcpy(fileSystem[fileSystemSize].name, name);
    fileSystem[fileSystemSize].is_directory = 1;
    fileSystem[fileSystemSize].metadata.creation_date = time(NULL);
    fileSystem[fileSystemSize].metadata.modification_date = time(NULL);
    fileSystemSize++;
}

void printMetadata(char *path) {
    for (int i = 0; i < fileSystemSize; i++) {
        if (strcmp(fileSystem[i].name, path) == 0) {
            printf("File Name: %s\n", fileSystem[i].name);
            printf("Size: %d bytes\n", fileSystem[i].metadata.size);
            printf("Creation Date: %s", ctime(&fileSystem[i].metadata.creation_date));
            printf("Modification Date: %s", ctime(&fileSystem[i].metadata.modification_date));
            return;
        }
    }
    printf("File not found: %s\n", path);
}

void resolvePath(char *path) {
  char *token = strtok(path, "/");
  char tempPath[200];
  strcpy(tempPath, currentPath);

  while (token != NULL) {
      if (strcmp(token, "..") == 0) {
          // Move one directory up
          char *lastSlash = strrchr(tempPath, '/');
          if (lastSlash != NULL) {
              *lastSlash = '\0'; // Remove the last directory from the path
          }
      } else if (strcmp(token, ".") == 0) {
          // Stay in the current directory
          continue;
      } else {
          // Append the directory or file name to the path
          if (strcmp(tempPath, "/") != 0) {
              strcat(tempPath, "/");
          }
          strcat(tempPath, token);
      }

      token = strtok(NULL, "/");
  }
  strcpy(currentPath, tempPath);
}

