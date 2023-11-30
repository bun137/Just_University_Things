#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES_PER_DIR 100
#define MAX_DIRS 100
#define MAX_PATH_LENGTH 255

struct File {
    char filename[50];
    int size; // Adding size attribute as metadata
    // Add more attributes for metadata if needed
};

struct Directory {
    char dirname[50];
    struct File files[MAX_FILES_PER_DIR];
    int file_count;
};

struct FileSystem {
    struct Directory directories[MAX_DIRS];
    int dir_count;
    int current_dir_index; // Index to track the current working directory
};

struct FileSystem fileSystem;

void createDirectory(char dirname[]) {
    if (fileSystem.dir_count < MAX_DIRS) {
        struct Directory newDir;
        strcpy(newDir.dirname, dirname);
        newDir.file_count = 0;
        fileSystem.directories[fileSystem.dir_count++] = newDir;
        printf("Directory '%s' created.\n", dirname);
    } else {
        printf("Cannot create directory. Maximum directories reached.\n");
    }
}

void createFile(char filename[]) {
    struct Directory* currentDir = &fileSystem.directories[fileSystem.current_dir_index];
    if (currentDir->file_count < MAX_FILES_PER_DIR) {
        struct File newFile;
        strcpy(newFile.filename, filename);
        newFile.size = 0; // Initialize size as 0 for new file
        currentDir->files[currentDir->file_count++] = newFile;
        printf("File '%s' created.\n", filename);
    } else {
        printf("Cannot create file. Maximum files reached in this directory.\n");
    }
}

void deleteFile(char filename[]) {
    struct Directory* currentDir = &fileSystem.directories[fileSystem.current_dir_index];
    for (int i = 0; i < currentDir->file_count; ++i) {
        if (strcmp(currentDir->files[i].filename, filename) == 0) {
            for (int j = i; j < currentDir->file_count - 1; ++j) {
                currentDir->files[j] = currentDir->files[j + 1];
            }
            currentDir->file_count--;
            printf("File '%s' deleted.\n", filename);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}

void deleteDirectory(char dirname[]) {
    for (int i = 0; i < fileSystem.dir_count; ++i) {
        if (strcmp(fileSystem.directories[i].dirname, dirname) == 0) {
            for (int j = i; j < fileSystem.dir_count - 1; ++j) {
                fileSystem.directories[j] = fileSystem.directories[j + 1];
            }
            fileSystem.dir_count--;
            printf("Directory '%s' deleted.\n", dirname);
            return;
        }
    }
    printf("Directory '%s' not found.\n", dirname);
}

void changeDirectory(char dirname[]) {
    if (strcmp(dirname, "..") == 0) {
        if (fileSystem.current_dir_index > 0) {
            fileSystem.current_dir_index--;
            printf("Moved to parent directory.\n");
        } else {
            printf("Already in the root directory.\n");
        }
        return;
    }

    for (int i = 0; i < fileSystem.dir_count; ++i) {
        if (strcmp(fileSystem.directories[i].dirname, dirname) == 0) {
            fileSystem.current_dir_index = i;
            printf("Current directory changed to '%s'.\n", dirname);
            return;
        }
    }
    printf("Directory '%s' not found.\n", dirname);
}

void listFiles() {
    struct Directory* currentDir = &fileSystem.directories[fileSystem.current_dir_index];
    printf("Files in '%s' directory:\n", currentDir->dirname);
    for (int i = 0; i < currentDir->file_count; ++i) {
        printf("- %s (%d bytes)\n", currentDir->files[i].filename, currentDir->files[i].size);
    }
}

char* resolveAbsolutePath(char* basePath, char* givenPath) {
    char* resolvedPath = malloc(MAX_PATH_LENGTH * sizeof(char));
    strcpy(resolvedPath, basePath);

    char* token = strtok(givenPath, "\\");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            int len = strlen(resolvedPath);
            while (len > 0 && resolvedPath[len - 1] != '\\') {
                resolvedPath[len - 1] = '\0';
                len--;
            }
            resolvedPath[len - 1] = '\0';
        } else {
            strcat(resolvedPath, "\\");
            strcat(resolvedPath, token);
        }
        token = strtok(NULL, "\\");
    }
    return resolvedPath;
}

void updateFileSize(char filename[], int newFileSize) {
    struct Directory* currentDir = &fileSystem.directories[fileSystem.current_dir_index];
    for (int i = 0; i < currentDir->file_count; ++i) {
        if (strcmp(currentDir->files[i].filename, filename) == 0) {
            currentDir->files[i].size = newFileSize;
            printf("File size updated for '%s'.\n", filename);
            return;
        }
    }
    printf("File '%s' not found.\n", filename);
}
char* findFilePath(char filename[]) {
    static char path[MAX_PATH_LENGTH];
    path[0] = '\0';

    for (int i = 0; i < fileSystem.dir_count; ++i) {
        struct Directory* currentDir = &fileSystem.directories[i];
        for (int j = 0; j < currentDir->file_count; ++j) {
            if (strcmp(currentDir->files[j].filename, filename) == 0) {
                strcpy(path, currentDir->dirname);
                strcat(path, "\\");
                strcat(path, filename);
                return path;
            }
        }
    }
    return NULL; // File not found
}

int main() {
    char command[50];
    char argument[50];

    fileSystem.dir_count = 0;
    fileSystem.current_dir_index = 0; // Start at index 0

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "create_dir") == 0) {
            scanf("%s", argument);
            createDirectory(argument);
        } else if (strcmp(command, "create_file") == 0) {
            scanf("%s", argument);
            createFile(argument);
        } else if (strcmp(command, "delete_file") == 0) {
            scanf("%s", argument);
            deleteFile(argument);
        } else if (strcmp(command, "delete_dir") == 0) {
            scanf("%s", argument);
            deleteDirectory(argument);
        } else if (strcmp(command, "change_dir") == 0) {
            scanf("%s", argument);
            changeDirectory(argument);
        } else if (strcmp(command, "list_files") == 0) {
            listFiles();
        } else if (strcmp(command, "resolve_path") == 0) {
            char basePath[MAX_PATH_LENGTH];
            char givenPath[MAX_PATH_LENGTH];
            scanf("%s %s", basePath, givenPath);
            char* absolutePath = resolveAbsolutePath(basePath, givenPath);
            printf("Absolute Path: %s\n", absolutePath);
            free(absolutePath);
        } else if (strcmp(command, "update_file_size") == 0) {
            int newFileSize;
            scanf("%s %d", argument, &newFileSize);
            updateFileSize(argument, newFileSize);
        } else if (strcmp(command, "exit") == 0) {
            break; // Exit the loop
        } else {
            printf("Invalid command.\n");
        } char filenameToFind[50];
    
    }

    return 0;
}