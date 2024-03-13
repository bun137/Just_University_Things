#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie {
  struct trie *children[26];
  int eof;
} TRIE;

TRIE *createNode() {
  TRIE *newNode = (TRIE *)malloc(sizeof(TRIE));
  for (int i = 0; i < 26; i++) {
    newNode->children[i] = NULL;
  }
  newNode->eof = 0;
  return newNode;
}

void insert(TRIE *root, char *exp) {
  TRIE *temp = root;
  while (*exp != '\0') {
    if (temp->children[*exp - 'a'] == NULL) {
      temp->children[*exp - 'a'] = createNode();
    }
    temp = temp->children[*exp - 'a'];
    exp++;
  }
  temp->eof = -1;
  printf("word has been stored hahahaha!\n");
}

void search(TRIE *root, char *exp) {
  char token;
  int index;
  int i = 0;
  token = exp[i];
  while (token != '\0') {
    index = token - 'a';
    if (root->children[index] == NULL) {
      printf("word not found\n");
    }
    root = root->children[index];
    i++;
    token = exp[i];
  }
  if (root->eof == -1) {
    printf("haloo the word has been foundd!\n");
  } else {
    printf("the word hasnt been found :(\n");
  }
}

int isKhali(TRIE *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      return 0;
    }
  }
  return 1;
}

TRIE *delete(TRIE *root, char *str, int level, int strleng) {
  if (root == NULL) {
    return root;
  }
  if (level == strleng) {
    if (root->eof == -1) {
      root->eof = 0;
    }
    if (isKhali(root)) {
      free(root);
      root = NULL;
    }
    return root;
  }
  int index = str[level] - 'a';
  root->children[index] =
      delete (root->children[index], str, level + 1, strleng);
  if (root->eof == 0 && isKhali(root)) {
    free(root);
    root = NULL;
  }
  return root;
}

int main(int argc, char *argv[]) {
  // menu driven program
  TRIE *root = createNode();
  char exp[100];
  int choice;
  while (1) {
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Exit\n");
    printf("4. Delete\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the word to be inserted: ");
      scanf("%s", exp);
      insert(root, exp);
      break;
    case 2:
      printf("Enter the word to be searched: ");
      scanf("%s", exp);
      search(root, exp);
      break;
    case 3:
      exit(0);
    case 4:
      printf("Enter the word to be deleted: ");
      scanf("%s", exp);
      delete (root, exp, 0, strlen(exp));
      break;
    default:
      printf("Invalid choice!\n");
    }
  }

  return EXIT_SUCCESS;
}
