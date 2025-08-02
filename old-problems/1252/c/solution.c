#include <stdlib.h>
#include <string.h>

int oddCells(
    int m, int n, int** indices, int indicesSize, int* indicesColSize) {
  (void)indicesColSize;

  int* rows = malloc(m * sizeof(int));
  memset(rows, 0, m * sizeof(int));

  int* cols = malloc(n * sizeof(int));
  memset(cols, 0, n * sizeof(int));

  for (int i = 0; i < indicesSize; ++i) {
    ++rows[indices[i][0]];
    ++cols[indices[i][1]];
  }

  int count = 0;
  for (int i = 0; i < m; ++i) {
    const int rowParity = rows[i] % 2;
    for (int j = 0; j < n; ++j) {
      if (rowParity != cols[j] % 2) ++count;
    }
  }

  return count;
}
