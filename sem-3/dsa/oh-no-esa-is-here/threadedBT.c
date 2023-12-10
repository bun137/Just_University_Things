#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *lchild;
  int data;
  struct node *rchild;
  int rflag;
} NODEE;

NODEE *createNode(int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->data = data;
  newNode->rflag = 1;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}

void moveLeft(NODEE *parent, int data) {
  NODEE *newNode = createNode(data);
  newNode->rchild = parent;
  parent->lchild = newNode;
}

void moveRight(NODEE *parent, int data) {
  NODEE *newNode = createNode(data);
  newNode->rchild = parent->rchild;
  parent->rchild = newNode;
  parent->rflag = 0;
}

void insert(NODEE **root, int data) {
  NODEE *curr = *root;
  NODEE *par = *root;
  if (*root == NULL) {
    NODEE *newNode = createNode(data);
    (*root) = newNode;
    return;
  }
  while (curr != NULL) {
    par = curr;
    if ((curr)->data > data) {
      curr = (curr)->lchild;
    } else if ((curr)->rflag == 1) {
      break;
    } else {
      curr = curr->rchild;
    }
  }
  if ((par)->data > data) {
    moveLeft(par, data);
  } else {
    moveRight(par, data);
  }
}
NODEE *leftChildsLeft(NODEE *root) {
  if (root == NULL) {
    return root;
  } else {
    while (root->lchild != NULL) {
      root = root->lchild;
    }
    return root;
  }
}

void inorder(NODEE *root) {
  root = leftChildsLeft(root);
  while (root != NULL) {
    printf("%d ", root->data);
    if (root->rflag == 1) {
      root = root->rchild;
    } else {
      root = root->rchild;
      root = leftChildsLeft(root);
    }
  }
}

int main(int argc, char *argv[]) {
  NODEE *root = NULL;
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  printf("Enter elements space separated: ");
  int element;
  for (int i = 0; i < n; i++) {
    scanf("%d", &element);
    insert(&root, element);
  }

  // inorder traversal
  inorder(root);

  return EXIT_SUCCESS;
}
