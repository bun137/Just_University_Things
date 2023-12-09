#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
  struct treeNode *rchild;
  int data;
  struct treeNode *lchild;
} TNODEE;

TNODEE *insertion(TNODEE *root, int data) {
  TNODEE *child = root;
  TNODEE *parentPrev = NULL;
  TNODEE *newNode = (TNODEE *)malloc(sizeof(TNODEE));
  newNode->data = data;
  newNode->rchild = NULL;
  newNode->lchild = NULL;
  if (root == NULL) {
    root = newNode;
    return root;
  } else {
    while (child != NULL) {
      parentPrev = child;
      if (data > child->data) {
        child = child->rchild;
      } else {
        child = child->lchild;
      }
    }
    if (parentPrev->data > data) {
      parentPrev->lchild = newNode;
    } else {
      parentPrev->rchild = newNode;
    }
  }
  return root;
}

void inorderTrav(TNODEE *root) {
  if (root == NULL) {
    return;
  }
  inorderTrav(root->lchild);
  printf("%d ", root->data);
  inorderTrav(root->rchild);
}

void postorderTrav(TNODEE *root) {
  if (root == NULL) {
    return;
  }
  postorderTrav(root->lchild);
  postorderTrav(root->rchild);
  printf("%d ", root->data);
}

void preorderTrav(TNODEE *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorderTrav(root->lchild);
  preorderTrav(root->rchild);
}

TNODEE *insucc(TNODEE *root) {
  TNODEE *curr;
  curr = root;
  curr = curr->rchild;
  while (curr->lchild != NULL) {
    curr = curr->lchild;
  }
  return curr;
}

TNODEE *deleteNode(TNODEE *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data > data) {
    root->lchild = deleteNode(root->lchild, data);
  } else if (root->data < data) {
    root->rchild = deleteNode(root->rchild, data);
  } else {
    if (root->rchild == NULL) {
      TNODEE *temp = root->lchild;
      free(root);
      return temp;
    } else if (root->lchild == NULL) {
      TNODEE *temp = root->rchild;
      free(root);
      return temp;
    }
    TNODEE *temp = insucc(root);
    root->data = temp->data;
    root->rchild = deleteNode(root->rchild, temp->data);
  }
  return root;
}

int height(TNODEE *root) {
  if (root == NULL) {
    return -1;
  }
  if (root->lchild == NULL && root->rchild == NULL) {
    return 0;
  }
  int lc;
  int rc;
  lc = height(root->lchild);
  rc = height(root->rchild);
  return fmax(rc, lc) + 1;
}

int minChild(TNODEE *root) {
  if (root == NULL) {
    return -1;
  }
  while (root->lchild != NULL) {
    root = root->lchild;
  }
  return root->data;
}

int countNode(TNODEE *root) {
  if (root == NULL) {
    return 0;
  } else {
    int lN;
    int rN;
    lN = countNode(root->lchild);
    rN = countNode(root->rchild);
    return (lN + rN + 1);
  }
}

int leafNode(TNODEE *root) {
  if (root == NULL) {
    return 0;
  } else {
    if (root->lchild == NULL && root->rchild == NULL) {
      return 1;
    } else {
      int lc = leafNode(root->lchild);
      int rc = leafNode(root->rchild);
      return lc + rc;
    }
  }
}

int main() {
  // menu driven program
  TNODEE *root = NULL;
  int choice;
  int data;

  while (1) {
    printf("1. insert\n");
    printf("2. delete\n");
    printf("3. inorder\n");
    printf("4. postorder\n");
    printf("5. preorder\n");
    printf("6. height\n");
    printf("7. minChild\n");
    printf("8. countNode\n");
    printf("9. leafNode\n");
    printf("10. exit\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("enter data: ");
      scanf("%d", &data);
      root = insertion(root, data);
      break;
    case 2:
      printf("enter data: ");
      scanf("%d", &data);
      root = deleteNode(root, data);
      break;
    case 3:
      inorderTrav(root);
      printf("\n");
      break;
    case 4:
      postorderTrav(root);
      printf("\n");
      break;
    case 5:
      preorderTrav(root);
      printf("\n");
      break;
    case 6:
      printf("height of the tree is: %d\n", height(root));
      break;
    case 7:
      printf("minChild of the tree is: %d\n", minChild(root));
      break;
    case 8:
      printf("countNode of the tree is: %d\n", countNode(root));
      break;
    case 9:
      printf("leafNode of the tree is: %d\n", leafNode(root));
      break;
    case 10:
      exit(0);
    default:
      printf("invalid choice\n");
    }
  }
}
