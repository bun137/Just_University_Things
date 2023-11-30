#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *right;
  int data;
  struct node *left;
  int rflagi;
} NODEE;

NODEE *createNode(int data) {
  NODEE *newNode = (NODEE *)malloc(sizeof(NODEE));
  newNode->right = NULL;
  newNode->data = data;
  newNode->left = NULL;
  newNode->rflagi = 1;
  return newNode;
}

void moveRight(NODEE *newNode, NODEE *parent) {
  newNode->right = parent->right;
  parent->right = newNode;
  newNode->rflagi = 1;
  parent->rflagi = 0;
}

void moveLeft(NODEE *newNode, NODEE *parent) {
  newNode->right = parent;
  parent->left = newNode;
  newNode->rflagi = 1;
}

void insert(NODEE **root, int data) {
  NODEE *newNode = createNode(data);
  if (*root == NULL) {
    *root = newNode;
    return;
  } else {
    NODEE *parent = *root;
    NODEE *curr = *root;

    while (curr != NULL) {
      parent = curr;
      if (curr->data > data) {
        curr = curr->left;
      } else if (curr->rflagi) {
        break; // get outtt!!!
      } else {
        curr = curr->right;
      }
    }
    if (data > parent->data) {
      moveRight(newNode, parent);
    } else {
      moveLeft(newNode, parent);
    }
  }
}

NODEE *leftChildsChild(NODEE *nodii) {
  if (nodii == NULL) { // nodii->left != NULL) {
    return nodii;
  } else {
    while (nodii->left != NULL) {
      nodii = nodii->left;
    }
  }
  return nodii;
}

void inorder(NODEE *nodii) {
  NODEE *rn = leftChildsChild(nodii);
  while (rn != NULL) {
    printf("%d ", rn->data);
    if (rn->rflagi) {
      rn = rn->right;
    } else {
      rn = leftChildsChild(rn->right);
    }
  }
}

int main(int argc, char *argv[]) {
  NODEE *root = NULL;
  int n, ele;
  printf("hallo how many eles do you wanna insert??\n");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &ele);
    insert(&root, ele);
  }

  inorder(root);
  return EXIT_SUCCESS;
}
