#include <stdio.h>
#include <stdlib.h>
#define MAXI 10

void setGraph(int mat[][MAXI]) {
  for (int i = 0; i < MAXI; i++) {
    for (int j = 0; j < MAXI; j++) {
      mat[i][j] = 0;
    }
  }
}

void setValue(int mat[][MAXI], int v1, int v2) { mat[v1][v2] = 1; }

void clearVisit(int arr[MAXI]) {
  for (int i = 0; i < MAXI; i++) {
    arr[i] = 0;
  }
}

void dfs(int source, int mat[][MAXI], int visited[]) {
  // int visited[MAXI];
  // clearVisit(visited);
  printf("%d\n", source);
  visited[source] = 1;
  for (int i = 0; i < MAXI; i++) {
    if (mat[source][i] && !visited[i]) {
      dfs(i, mat, visited);
    }
  }
}
int eleExit(int mat[][MAXI], int i) {
  for (int j = 0; j < MAXI; j++) {
    if (mat[i][j] == 1 || mat[j][i] == 1) {
      return 1;
    }
  }
  return 0;
}

void bfs(int mat[][MAXI], int source, int visited[]) {
  int q[MAXI];
  int front = 0;
  int rear = -1;

  q[++rear] = source;
  visited[source] = 1;
  int curr;
  while (front <= rear) {
    curr = q[front++];
    printf("%d ", curr);
    for (int i = 0; i < MAXI; i++) {
      if (visited[i] == 0 && mat[curr][i]) {
        q[++rear] = i;
        visited[i] = 1;
      }
    }
  }
}

int isStronglyConnected(int mat[][MAXI]) {
  int visited[MAXI];
  clearVisit(visited);
  for (int i = 0; i < MAXI; i++) {
    if (!eleExit(mat, i)) {
      continue;
    }
    dfs(i, mat, visited);
    for (int j = 0; j < MAXI; j++) {
      if (visited[j] == 0 && eleExit(mat, j)) {
        return 0;
      }
    }
    clearVisit(visited);
  }
  return 1;
}

int isWeaklyConnected(int mat[][MAXI]) {
  int visited[MAXI];
  clearVisit(visited);
  int flag = 1;
  for (int i = 0; i < MAXI; i++) {
    flag = 1;
    if (!eleExit(mat, i)) {
      continue;
    }
    dfs(i, mat, visited);
    for (int j = 0; j < MAXI; j++) {
      if (visited[j] == 0 && eleExit(mat, j)) {
        flag = 0;
      }
    }
    if (flag == 1) {
      return 1;
    }
    clearVisit(visited);
  }
  return 0;
}

int main(int argc, char *argv[]) {

  int mat[MAXI][MAXI];
  setGraph(mat);

  int egdes;
  printf("how many edges do yo want? ");
  scanf("%d", &egdes);

  int v1, v2;
  for (int k = 0; k < egdes; k++) {
    printf("enter v1 and then v2 : v1->v2 ");
    scanf("%d %d", &v1, &v2);
    setValue(mat, v1, v2);
  }
  int sour;
  int visited[MAXI];
  clearVisit(visited);
  printf("bro tell source ");
  scanf("%d", &sour);
  dfs(sour, mat, visited);
  for (int i = 0; i < MAXI; i++) {
    if (visited[i] == 0 && eleExit(mat, i)) {
      dfs(i, mat, visited);
    }
  }
  clearVisit(visited);
  printf("cupcake says hi to you bf!\n");
  bfs(mat, sour, visited);
  for (int i = 0; i < MAXI; i++) {
    if (visited[i] == 0 && eleExit(mat, i)) {
      bfs(mat, i, visited);
    }
  }
  clearVisit(visited);
  printf("\n");
  if (isStronglyConnected(mat)) {
    printf("yep strong conection \n");
  } else if (isWeaklyConnected(mat)) {
    printf(" weak connectino -_-\n");
  } else {
    printf("bruh no connection only-\n");
  }
  return EXIT_SUCCESS;
}
