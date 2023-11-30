#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
   char name[100];
   int size;
   char creation_date[20];
   char modification_date[20];
   struct Node* next;
};
struct TreeNode {
   char name[100];
   struct Node* file_list;
   struct Node* directory_list;
   struct TreeNode* parent;
   struct TreeNode* next;
};
struct Node* create_node(char name[], int size, char creation_date[], char modification_date[]) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   strcpy(new_node->name, name);
   new_node->size = size;
   strcpy(new_node->creation_date, creation_date);
   strcpy(new_node->modification_date, modification_date);
   new_node->next = NULL;
   return new_node;
}

char* resolve_file_path(char* relative_path) {
  char* absolute_path = realpath(relative_path, NULL);
  if(absolute_path == NULL) {
      printf("Cannot find file with name[%s]\n", relative_path);
  }
  return absolute_path;
}


void insert_node(struct Node** head, struct Node* new_node) {
   new_node->next = (*head);
   (*head) = new_node;
}

struct TreeNode* create_tree_node(char name[]) {
   struct TreeNode* new_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
   strcpy(new_node->name, name);
   new_node->file_list = NULL;
   new_node->directory_list = NULL;
   new_node->parent = NULL;
   new_node->next = NULL;
   return new_node;
}

void insert_tree_node(struct TreeNode** head, struct TreeNode* new_node) {
   new_node->next = (*head);
   (*head) = new_node;
}

struct Node* search_node(struct Node* head, char name[]) {
   struct Node* current = head;
   while (current != NULL) {
       if (strcmp(current->name, name) == 0)
           return current;
       current = current->next;
   }
   return NULL;
}

struct TreeNode* search_tree_node(struct TreeNode* head, char name[]) {
   struct TreeNode* current = head;
   while (current != NULL) {
       if (strcmp(current->name, name) == 0)
           return current;
       current = current->next;
   }
   return NULL;
}
int main() {
   struct Node* file_list = NULL;
   struct TreeNode* directory_tree = NULL;
   char command[100];
   char name[100];
   int size;
   char creation_date[20];
   char modification_date[20];

   while (1) {
       printf("Enter command: ");
       scanf("%s", command);

       if (strcmp(command, "exit") == 0)
           break;

       printf("Enter name: ");
       scanf("%s", name);

         if (strcmp(command, "create_file") == 0) {
          printf("Enter size: ");
          scanf("%d", &size);
          printf("Enter creation date: ");
          scanf("%s", creation_date);
          printf("Enter modification date: ");
          scanf("%s", modification_date);

          struct Node* new_file = create_node(name, size, creation_date, modification_date);
          insert_node(&file_list, new_file);
      }

      if (strcmp(command, "create_directory") == 0) {
          struct TreeNode* new_directory = create_tree_node(name);
          insert_tree_node(&directory_tree, new_directory);
      }

      if (strcmp(command, "search_file") == 0) {
          struct Node* file = search_node(file_list, name);
          if (file != NULL) {
              printf("Found file with name: %s, size: %d, creation date: %s, modification date: %s\n",
                    file->name, file->size, file->creation_date, file->modification_date);
          } else {
              printf("File not found\n");
          }
      }

      if (strcmp(command, "search_directory") == 0) {
          struct TreeNode* directory = search_tree_node(directory_tree, name);
          if (directory != NULL) {
              printf("Found directory with name: %s\n", directory->name);
          } else {
              printf("Directory not found\n");
          }
      }
      if (strcmp(command, "resolve_file_path") == 0) {
   char* absolute_path = resolve_file_path(name);
   if(absolute_path != NULL) {
       FILE* file = fopen(absolute_path, "r");
       if(file == NULL) {
           printf("Cannot open file[%s]\n", absolute_path);
       } else {
           printf("File opened successfully\n");
           fclose(file);
       }
       free(absolute_path);
   }
}

  }

  return 0;
}
