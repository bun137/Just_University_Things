#include <stdio.h>
#include <stdlib.h>
#define NUM_SPACE 5

typedef struct node {
  int data;
  struct node *rchild;
  struct node *lchild;
} node_t;

node_t *get_node(int data);
void insert(node_t **root, int data);
void preorder(node_t *root);
void inorder(node_t *root);
void postorder(node_t *root);
void display(node_t *root, int space);

int main(int argc, char *argv[]) {

  int choice;
  int data;
  node_t *root = NULL;

  do {
    printf("1. Insert\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Postorder\n");
    printf("5. Display\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insert(&root, data);
      break;

    case 2:
      preorder(root);
      printf("\n");
      break;

    case 3:
      inorder(root);
      printf("\n");
      break;

    case 4:
      postorder(root);
      printf("\n");
      break;

    case 5:
      display(root, 0);
      break;

    case 6:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice\n");
      break;
    }

  } while (choice != 6);

  return EXIT_SUCCESS;
}

node_t *get_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->lchild = NULL;
  new_node->rchild = NULL;
  return new_node;
}

void insert(node_t **root, int data) {
  node_t *new_node = get_node(data);
  if (*root == NULL) {
    *root = new_node;
    return;
  } else {
    node_t *prev = *root;
    node_t *current = *root;
    while (current != NULL) {
      prev = current;

      if (data < current->data) {
        current = current->lchild;
      } else {
        current = current->rchild;
      }
    }

    if (data < prev->data) {
      prev->lchild = new_node;
    } else {
      prev->rchild = new_node;
    }
  }
}

void preorder(node_t *root) {
 if(root!= NULL){
  printf("%d ", root->data);
  preorder(root->lchild);
  preorder(root->rchild);}
}

void inorder(node_t *root) {
  if(root != NULL){
  preorder(root->lchild);
  printf("%d ", root->data);
  preorder(root->rchild);}
}

void postorder(node_t *root) {
  if (root != NULL) {
    preorder(root->lchild);
  preorder(root->rchild);
  printf("%d ", root->data);
  }
  
}

void display(node_t *root, int space) {
  if (root == NULL) {
    return;
  }

  space += NUM_SPACE;

  display(root->rchild, space);

  for (int i = NUM_SPACE; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);

  display(root->lchild, space);
}
