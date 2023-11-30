

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct Metadata {
   char name[256];
   long size;
   time_t creation_date;
   time_t modification_date;
} Metadata;
typedef struct Node {
   Metadata metadata;
   struct Node* left;
   struct Node* right;
   struct Node* next;
} Node;
void add_to_tree(Node** root, Metadata metadata) {
   if (*root == NULL) {
       *root = (Node*)malloc(sizeof(Node));
       (*root)->metadata = metadata;
       (*root)->left = NULL;
       (*root)->right = NULL;
       (*root)->next = NULL;
   } else if (strcmp((*root)->metadata.name, metadata.name) > 0) {
       add_to_tree(&(*root)->left, metadata);
   } else if (strcmp((*root)->metadata.name, metadata.name) < 0) {
       add_to_tree(&(*root)->right, metadata);
   }
}

void add_to_list(Node** head, Metadata metadata) {
   Node* new_node = (Node*)malloc(sizeof(Node));
   new_node->metadata = metadata;
   new_node->next = NULL;

   if (*head == NULL) {
       *head = new_node;
   } else {
       Node* last = *head;
       while (last->next != NULL) {
           last = last->next;
       }
       last->next = new_node;
   }
}
void print_metadata(Node* node) {
   if (node != NULL) {
       printf("Name: %s\n", node->metadata.name);
       printf("Size: %ld\n", node->metadata.size);
       printf("Creation Date: %s", ctime(&node->metadata.creation_date));
       printf("Modification Date: %s", ctime(&node->metadata.modification_date));
       printf("\n");

       print_metadata(node->left);
       print_metadata(node->right);
       print_metadata(node->next);
   }
}
