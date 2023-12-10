#include <stdio.h>
#include <stdlib.h>
#define MAX 64

void setMatrix(int mat[MAX][MAX]) {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      mat[i][j] = 0;
    }
  }
}

void clearVisited(int arr[]) {
  for (int i = 0; i < MAX; i++) {
    arr[i] = 0;
  }
}

void dfs(int mat[MAX][MAX], int arr[], int source) {
  printf("%d ", source);
  arr[source] = 1;
  for (int i = 0; i < MAX; i++) {
    if (mat[source][i] && !arr[i]) {
      dfs(mat, arr, i);
    }
  }
}

void bfs(int mat[][MAX], int arr[], int source) {
  int que[MAX];
  int f = 0;
  int b = -1;
  que[++b] = source;
  arr[source] = 1;
  int curr;
  while (f <= b) {
    curr = que[f++];
    printf("%d ", curr);
    for (int i = 0; i < MAX; i++) {
      if (arr[i] == 0 && mat[curr][i]) {
        que[++b] = i;
        arr[i] = 1;
      }
    }
  }
}

int doesEleExist(int i, int mat[][MAX]) {
  for (int j = 0; j < MAX; j++) {
    if (mat[i][j] || mat[j][i]) {
      return 1;
    }
  }
  return 0;
}

int isStronglyConnecti(int mat[][MAX]) {
  int visited[MAX];
  clearVisited(visited);
  for (int i = 0; i < MAX; i++) {
    if (doesEleExist(i, mat) == 0) {
      continue;
    }
    dfs(mat, visited, i);
    for (int j = 0; j < MAX; j++) {
      if (!visited[j] && doesEleExist(j, mat)) {
        return 0;
      }
    }
    clearVisited(visited);
  }
  return 1;
}

int isWeaklyConntecti(int mat[MAX][MAX]) {
  int visited[MAX];
  clearVisited(visited);
  int haveYouBeenVisited;
  for (int i = 0; i < MAX; i++) {
    haveYouBeenVisited = 1;
    if (!doesEleExist(i, mat)) {
      continue;
    }
    dfs(mat, visited, i);
    for (int j = 0; j < MAX; j++) {
      if (!visited[j] && doesEleExist(j, mat)) {
        haveYouBeenVisited = 0;
      }
    }
    if (haveYouBeenVisited) {
      return 1;
    }
    clearVisited(visited);
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int mat[MAX][MAX];
  setMatrix(mat);

  int choice;
  while (1) {
    printf("\n\n1. Enter Edges\n2. DFS\n3. BFS\n4.Connection\n0. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    int v1, v2, source, visited[MAX];
    switch (choice) {
    case 1:
      while (1) {
        printf("enter v1 and v2: ");
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 && v2 == -1) {
          break;
        }
        mat[v1][v2] = 1;
      }
      printf("\n");
      for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
          printf("%d ", mat[i][j]);
        }
        printf("\n");
      }
      break;
    case 2:
      printf("Enter source: ");
      scanf("%d", &source);
      clearVisited(visited);
      dfs(mat, visited, source);
      for (int i = 0; i < MAX; i++) {
        if (doesEleExist(i, mat) && !visited[i]) {
          dfs(mat, visited, i);
        }
      }
      break;
    case 3:
      printf("Enter source: ");
      scanf("%d", &source);
      clearVisited(visited);
      bfs(mat, visited, source);
      for (int i = 0; i < MAX; i++) {
        if (doesEleExist(i, mat) && !visited[i]) {
          bfs(mat, visited, i);
        }
      }
      break;
    case 4:
      if (isStronglyConnecti(mat)) {
        printf("\nand and and anddddd yepp it is strongly connected! nice\n");
      } else if (isWeaklyConntecti(mat)) {
        printf("\nnot bad is weakly connected!\n");
      } else {
        printf("no network here, no connection only pa :facepalm:\n");
      }
    case 0:
      return EXIT_SUCCESS;
    }
  }
  return EXIT_SUCCESS;
}
