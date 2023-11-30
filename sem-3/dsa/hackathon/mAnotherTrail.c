#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A structure to represent a directory
typedef struct Dir {
    char name[50];
    int file_count;
    struct File *files;
    int dir_count;
    struct Dir *dirs;
} Dir;

// A structure to represent a file
typedef struct File {
    char name[50];
    int size;
    char *content;
} File;

// Function to create a new directory
Dir *create_dir(char *name) {
    Dir *new_dir = (Dir *)malloc(sizeof(Dir));
    strcpy(new_dir->name, name);
    new_dir->file_count = 0;
    new_dir->files = NULL;
    new_dir->dir_count = 0;
    new_dir->dirs = NULL;
    return new_dir;
}

// Function to create a new file
File *create_file(char *name, int size, char *content) {
    File *new_file = (File *)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->content = content;
    return new_file;
}

// Function to add a file to a directory
void add_file(Dir *dir, File *file) {
    dir->files = (File *)realloc(dir->files, sizeof(File) * (dir->file_count + 1));
    dir->files[dir->file_count++] = *file;
}

// Function to add a directory to a directory
void add_dir(Dir *dir, Dir *new_dir) {
    dir->dirs = (Dir *)realloc(dir->dirs, sizeof(Dir) * (dir->dir_count + 1));
    dir->dirs[dir->dir_count++] = *new_dir;
}

// Function to search for a file in a directory
File *search_file(Dir *dir, char *name) {
    for (int i = 0; i < dir->file_count; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            return &dir->files[i];
        }
    }
    return NULL;
}

// Function to search for a directory in a directory
Dir *search_dir(Dir *dir, char *name) {
    for (int i = 0; i < dir->dir_count; i++) {
        if (strcmp(dir->dirs[i].name, name) == 0) {
            return &dir->dirs[i];
        }
    }
    return NULL;
}

// Function to move to the parent directory
Dir *move_to_parent(Dir *current_dir) {
    // If the current directory is not the root, move to its parent
    if (strcmp(current_dir->name, "root") != 0) {
        return search_dir(current_dir->dirs, "..");
    }
    return current_dir; // If already at root, stay at root
}

// Function to prompt the user for input
void prompt(char *message, char *buffer) {
    printf("%s", message);
    fgets(buffer, 50, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

// Function to display the contents of a directory and its subdirectories recursively
void display_directory_hierarchy(Dir *dir, int depth) {
    // Print the current directory name
    for (int i = 0; i < depth; i++) {
        printf("  "); // Adjust spacing for hierarchy level
    }
    printf("%s/\n", dir->name);

    // Print files in the current directory
    for (int i = 0; i < dir->file_count; i++) {
        for (int j = 0; j < depth + 1; j++) {
            printf("  "); // Adjust spacing for hierarchy level
        }
        printf("%s (Size: %d, Content: %s)\n", dir->files[i].name, dir->files[i].size, dir->files[i].content);
    }

    // Recursively display subdirectories
    for (int i = 0; i < dir->dir_count; i++) {
        display_directory_hierarchy(&dir->dirs[i], depth + 1);
    }
}

// Function to create a new file in the current directory
void create_file_in_current_dir(Dir *current_dir, char *file_name, int file_size, char *file_content) {
    File *new_file = create_file(file_name, file_size, file_content);
    add_file(current_dir, new_file);
}
void create_and_save_file(Dir *current_dir, char *file_name, int file_size, char *file_content) {
    File *new_file = create_file(file_name, file_size, file_content);
    add_file(current_dir, new_file);
}
void display_files_in_directory(Dir *dir) {
    printf("Files in the current directory:\n");
    
    for (int i = 0; i < dir->file_count; i++) {
        printf("%s (Size: %d, Content: %s)\n", dir->files[i].name, dir->files[i].size, dir->files[i].content);
    }
}

int main() {
    // Create directories and files
    Dir *root = create_dir("root");
    Dir *dir1 = create_dir("dir1");
    Dir *dir2 = create_dir("dir2");
    File *file1 = create_file("file1.txt", 5, "Hello");
    File *file2 = create_file("file2.txt", 10, "World!");

    // Manually assign the file1.txt file into the dir1 directory
    dir1->files = (File *)realloc(dir1->files, sizeof(File) * (dir1->file_count + 1));
    dir1->files[dir1->file_count++] = *file1;

    // Add files and directories to the root directory
    add_file(root, file1);
    add_file(root, file2);
    add_dir(root, dir1);
    add_dir(root, dir2);

    // Initialize navigation variables
    Dir *current_dir = root;
    char input[50];
    char command[50];
    char arg1[50];
    char arg2[50];

while (1) {
        prompt("> ", input);
        sscanf(input, "%s %s %s", command, arg1, arg2);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "cd") == 0) {
            // ... (your existing code)

        } else if (strcmp(command, "ls") == 0) {
            if (strcmp(arg1, "") == 0) {
                // Display the current directory hierarchy
                display_directory_hierarchy(current_dir, 0);
            } else if (strcmp(arg1, "-l") == 0) {
                // Display detailed information about all files in the current directory
                display_files_in_directory(current_dir);
            } else {
                File *found_file = search_file(current_dir, arg1);
                if (found_file != NULL) {
                    printf("%s\n", found_file->content);
                } else {
                    printf("Error: file not found\n");
                }
            }
        } else if (strcmp(command, "create") == 0) {
            // Corrected function name
            create_and_save_file(current_dir, arg1, atoi(arg2), ""); // Assuming empty content for now
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}