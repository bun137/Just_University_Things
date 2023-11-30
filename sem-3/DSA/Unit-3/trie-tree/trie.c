#include <stdio.h>
#include <stdlib.h>
typedef struct trieNode {
  int endOfWord;
  struct trieNode *children[26];
} TRIENODII;

TRIENODII *getNode() {
  TRIENODII *newnode;
  newnode = malloc(sizeof(TRIENODII));
  newnode->endOfWord = 0;
  for (int i = 0; i < 26; i++) {
    newnode->children[i] = NULL;
  }
  return newnode;
}

void insert(TRIENODII *root, char *str) {
  char token;
  int index;
  int i = 0;
  token = str[i];
  while (token != '\0') {
    index = token - 'a';
    if (root->children[index] == NULL) {
      root->children[index] = getNode();
    }
    root = root->children[index];
    i++;
    token = str[i];
  }
  root->endOfWord = 1;
  printf("Word has been stored! \n");
}

void search(TRIENODII *root, char *str) {
  char token;
  int index;
  int i = 0;
  token = str[i];
  while (token != '\0') {
    index = token - 'a';
    if (root->children[index] == NULL) {
      printf("Word not found! \n");
      return;
    }
    root = root->children[index];
    i++;
    token = str[i];
  }
  if (root->endOfWord == 1) {
    printf("Word found! \n");
  } else {
    printf("Word not found! \n");
  }
}

int main() {
  TRIENODII *root;
  char str[100];
  root = getNode();
  printf("Enter the string to be stored: ");
  scanf("%s", str);
  insert(root, str);

  char searchWord[100];
  printf("Enter the string to be searched: ");
  scanf("%s", searchWord);
  search(root, searchWord);

  return 0;
}
