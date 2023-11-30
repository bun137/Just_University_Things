
// TODO This doesn't work

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
  int rthread;
} node_t;

void insert_node(node_t **tree, int data);
void inorder(node_t *tree);

// helper functions
node_t *getNode(int data);
void setLeft(node_t *prev, node_t *node);
void setRight(node_t *prev, node_t *node);
node_t *leftmost(node_t *node);

int main(int argc, char *argv[]) {
  node_t *tree = NULL;
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  n = 5;
  printf("Enter elements space separated: ");
  int elements[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &elements[i]);
  }

  // insertion of all elements
  for (int i = 0; i < n; i++) {
    insert_node(&tree, elements[i]);
  }

  // inorder traversal
  inorder(tree);

  return EXIT_SUCCESS;
}

node_t *getNode(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->rthread = 1;
  return new_node;
}

void insert_node(node_t **root, int data) {
  node_t *new_node = getNode(data);
  if (*root == NULL) {
    *root = new_node;
    return;
  } else {
    node_t *prev = *root;
    node_t *current = *root;
    while (current != NULL) {
      prev = current;
      if (data < current->data) {
        current = current->left;
      } else if (current->rthread) {
        break;
      } else {
        current = current->right;
      }
    }

    if (data < prev->data) {
      setLeft(prev, new_node);
    } else {
      setRight(prev, new_node);
    }
  }
}

void setLeft(node_t *prev, node_t *node) {
  prev->left = node;
  node->right = prev;
  node->rthread = 1;
}

void setRight(node_t *prev, node_t *node) {
  node->right = prev->right;
  prev->rthread = 0;
  prev->right = node;
}

node_t *leftmost(node_t *node) {
  if (node == NULL) {
    return node;
  } else {
    while (node->left != NULL) {
      node = node->left;
    }
    return node;
  }
}

void inorder(node_t *tree) {
  node_t *current = leftmost(tree);
  while (current != NULL) {
    printf("%d ", current->data);
    if (current->rthread) {
      current = current->right;
    } else {
      current = leftmost(current->right);
    }
  }
  printf("\n");
}
