#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  struct node *ptr;
  char name[64];
  int srn;
} node_t;

typedef struct hashtable {
  node_t **arr;
  int size;
} hash_t;

int getHash(int srn) { return srn % 10; } // hash function

void insert(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  node_t *newNode = (node_t *)malloc(sizeof(node_t));
  newNode->srn = srn;
  strcpy(newNode->name, name);
  newNode->ptr = hashTable->arr[index];
  hashTable->arr[index] = newNode;
}

int search(hash_t *hashTable, int srn, char *name) {
  int index = getHash(srn);
  node_t *head = hashTable->arr[index];
  while (head != NULL) {
    if (head->srn == srn) {
      printf("found srn!\n");
      strcpy(name, head->name);
      printf("the name is %s\n", name);
      return 1;
    }
    head = head->ptr;
  }
  return 0;
}

int delete(hash_t *hashTable, int srn) {
  int index = getHash(srn);
  node_t *curr = hashTable->arr[index];
  node_t *prev = NULL;
  while (curr != NULL) {
    if (curr->srn == srn) {
      if (prev == NULL) {
        hashTable->arr[index] = curr->ptr;
        free(curr);
        return 1;
      }
      prev->ptr = curr->ptr;
      free(curr);
      return 1;
    }
    curr = curr->ptr;
  }
  return 0;
}

void display(hash_t *hashTable) {
  node_t *head;
  for (int i = 0; i < hashTable->size; i++) {
    printf("%d ", i);
    for (head = hashTable->arr[i]; head != NULL; head = head->ptr) {
      printf("-> %d ", head->srn);
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  printf("Enter hash table size: ");
  int size;
  scanf("%d", &size);
  hash_t hashTable;
  hashTable.arr = (node_t **)malloc(sizeof(node_t *));
  // do
  // make sure to make all hashTable arr values as NULL. you might have this
  // in an init hashTable func
  hashTable.size = size;
  for (int o = 0; o < hashTable.size; o++) {
    hashTable.arr[o] = NULL;
  }
  int choice;
  while (1) {
    printf("1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter SRN: ");
      int srn;
      scanf("%d", &srn);
      printf("Enter name: ");
      char name[64];
      scanf("%s", name);
      insert(&hashTable, srn, name);
      break;
    case 2:
      printf("Enter SRN: ");
      scanf("%d", &srn);
      if (search(&hashTable, srn, name)) {
        // remember search returns if it was found or not
        printf("Found %s with srn %d\n", name, srn);
      } else {
        printf("Not found :(\n");
      }
      break;
    case 3:
      // similar to search
      printf("Enter SRN: ");
      scanf("%d", &srn);
      if (delete (&hashTable, srn)) {
        printf("Deleted srn %d\n", srn);
      } else {
        printf("Not found :(\n");
      }

      break;
    case 4:
      display(&hashTable);
      break;
    case 0:
      exit(0);
    }
  }
  return EXIT_SUCCESS;
}
