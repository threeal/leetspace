int arr[100];

int uniquePaths(int m, int n) {
  for (int i = 0; i < m; ++i) arr[i] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      arr[j] += arr[j - 1];
    }
  }
  return arr[m - 1];
}
