#include <stdio.h>

int findPivot(int arr[], int low, int high) {
  if (high < low)
    return -1;
  if (high == low)
    return low;

  int mid = (low + high) / 2;
  if (mid < high && arr[mid] > arr[mid + 1])
    return mid;
  if (mid > low && arr[mid] < arr[mid - 1])
    return (mid - 1);

  if (arr[low] >= arr[mid])
    return findPivot(arr, low, mid - 1);
  return findPivot(arr, mid + 1, high);
}

int searchForNumber(int N, int *arr, int T) {
  int sum = 0;
  int pivot = findPivot(arr, 0, N - 1);

  if (pivot == -1) {
    int l = 0;
    int r = N - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      sum += m;
      if (arr[m] == T)
        return sum;
      if (arr[m] < T)
        l = m + 1;
      else
        r = m - 1;
    }
  } else {
    int l = 0;
    int r = N - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int m_index = (m + pivot) % N;
      sum += m_index;
      if (arr[m_index] == T)
        return sum;
      if (arr[m_index] < T)
        l = m + 1;
      else
        r = m - 1;
    }
  }

  return -1;
}

int main() {
  int N;
  scanf("%d", &N);
  int code_array[N];
  for (int i = 0; i < N; i++)
    scanf("%d", &code_array[i]);
  int target;
  scanf("%d", &target);
  int res = searchForNumber(N, code_array, target);
  printf("%d", res);
  return 0;
}
