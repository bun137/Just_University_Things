#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int tsp_lexicographic(int n, char **city_names, int **distan) {
  char t[n];
  for (int i = 0; i < n; i++)
    t[i] = 'a' + i;
  int minDistan = INT_MAX;
  char minVal[n];
  bool nextPattern = true;
  do {
    int total_dist = 0;
    for (int i = 0; i < n - 1; i++) {
      int c1 = t[i] - 'a';
      int c2 = t[i + 1] - 'a';
      total_dist += distan[c1][c2];
    }
    total_dist += distan[t[n - 1] - 'a'][t[0] - 'a'];
    if (total_dist < minDistan) {
      minDistan = total_dist;
      for (int i = 0; i < n; i++)
        minVal[i] = t[i];
    }
    int i = n - 2;
    while (i >= 0 && t[i] >= t[i + 1])
      i--;
    if (i < 0) {
      nextPattern = false;
    } else {
      int j = n - 1;
      while (t[j] <= t[i])
        j--;
      char temp = t[i];
      t[i] = t[j];
      t[j] = temp;
      int first = i + 1;
      int last = n - 1;
      while (first < last) {
        temp = t[first];
        t[first] = t[last];
        t[last] = temp;
        first++;
        last--;
      }
    }
  } while (nextPattern);
  for (int i = 0; i < n; i++)
    printf("%s ", city_names[minVal[i] - 'a']);
  printf("\n%d\n", minDistan);
  return minDistan;
}

int main() {
  int n;
  scanf("%d", &n);
  char **city_names = malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    city_names[i] = malloc(20 * sizeof(char));
    if (city_names[i] == NULL) {
      exit(EXIT_FAILURE);
    }
    scanf("%s", city_names[i]);
  }
  int **distan = malloc(n * sizeof(int *));
  if (distan == NULL) {
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < n; i++) {
    distan[i] = malloc(n * sizeof(int));
    if (distan[i] == NULL) {
      exit(EXIT_FAILURE);
    }
    for (int j = 0; j < n; j++) {
      scanf("%d", &distan[i][j]);
    }
  }
  tsp_lexicographic(n, city_names, distan);
  // Free allocated memory
  for (int i = 0; i < n; i++) {
    free(city_names[i]);
  }
  free(city_names);
  for (int i = 0; i < n; i++) {
    free(distan[i]);
  }
  free(distan);
  return 0;
}
