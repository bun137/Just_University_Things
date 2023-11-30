#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h> // Include for getcwd
#include <time.h>
// Structure to store metadata information
struct Metadata {
    size_t size;
    time_t creation_time;
    time_t modification_time;
};
// Structure to represent a file or directory entry
struct FileEntry {
    char name[256];
    int is_directory;
    struct Metadata metadata;
};
// Function to get metadata for a file or directory
struct Metadata getMetadata(const char *path) {
    struct Metadata metadata;
    struct stat fileStat;
    if (stat(path, &fileStat) == 0) {
        metadata.size = fileStat.st_size;
        metadata.creation_time = fileStat.st_ctime;
        metadata.modification_time = fileStat.st_mtime;
    } else {
        // Set default values if metadata retrieval fails
        metadata.size = 0;
        metadata.creation_time = 0;
        metadata.modification_time = 0;
    }
    return metadata;
}
// Function to resolve the absolute path
char *resolvePath(const char *cwd, const char *path) {
    char *absolutePath;
    if (path[0] == '/') {
        // Absolute path
        absolutePath = strdup(path);
    } else {
        // Relative path
        absolutePath = malloc(strlen(cwd) + strlen(path) + 2); // +2 for '/' and '\0'
        strcpy(absolutePath, cwd);
        if (strlen(cwd) > 0 && cwd[strlen(cwd) - 1] != '/') {
            strcat(absolutePath, "/");
        }
        strcat(absolutePath, path);
    }
    return absolutePath;
}
// Function to list files and directories in the current directory
void listDirectory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }
    printf("Contents of %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
// Function to create a new file
void createFile(const char *cwd, const char *filename) {
    char *absolutePath = resolvePath(cwd, filename);
    FILE *file = fopen(absolutePath, "w");
    if (file != NULL) {
        printf("File '%s' created successfully.\n", filename);
        fclose(file);
    } else {
        perror("Error creating file");
    }
    free(absolutePath);
}
int main() {
    // Current working directory
    char cwd[256];
    // Buffer for user input
    char input[256];
    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("Unable to get current working directory");
        return 1;
    }
    while (1) {
        // Display current working directory
        printf("\nCurrent Directory: %s\n", cwd);
        // Display menu
        printf("\nMenu:\n");
        printf("1. List Files and Directories\n");
        printf("2. Change Directory\n");
        printf("3. Get File Metadata\n");
        printf("4. Create File\n");
        printf("5. Exit\n");
 
        // Get user input
        printf("Enter option (1-5): ");
        fgets(input, sizeof(input), stdin);
 
        // Process user input
        switch (atoi(input)) {
            case 1:
                listDirectory(cwd);
                break;
            case 2:
                printf("Enter directory name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline character
                // Change directory
                char *newDirectory = resolvePath(cwd, input);
                if (chdir(newDirectory) == 0) {
                    getcwd(cwd, sizeof(cwd));
                } else {
                    perror("Error changing directory");
                }
                free(newDirectory);
                break;
 
            case 3:
                printf("Enter file name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline character
                // Resolve the absolute path
                char *absolutePath = resolvePath(cwd, input);
                // Access metadata using the absolute path
                struct Metadata metadata = getMetadata(absolutePath);
                // Display metadata information
                printf("\nFile Size: %lu bytes\n", metadata.size);
                printf("Creation Time: %s", ctime(&metadata.creation_time));
                printf("Modification Time: %s", ctime(&metadata.modification_time));
                // Free allocated memory
                free(absolutePath);
                break;
 
            case 4:
                printf("Enter new file name: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline character
                createFile(cwd, input);
                break;
 
            case 5:
                // Exit the program
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}