#include <stdlib.h>
#include <string.h>

int countUnguarded(
    int m, int n, int** guards, int guardsSize, int* guardsColSize,
    int** walls, int wallsSize, int* wallsColSize) {
  (void)guardsColSize;
  (void)wallsColSize;

  char* cells = malloc(m * n * sizeof(char));
  memset(cells, 0, m * n * sizeof(char));

  for (int i = 0; i < guardsSize; ++i) {
    cells[guards[i][0] * n + guards[i][1]] = 1;
  }

  for (int i = 0; i < wallsSize; ++i) {
    cells[walls[i][0] * n + walls[i][1]] = 2;
  }

  for (int i = 0; i < guardsSize; ++i) {
    for (int j = guards[i][0] + 1; j < m; ++j) {
      if (cells[j * n + guards[i][1]] > 0) break;
      cells[j * n + guards[i][1]] = -1;
    }

    for (int j = guards[i][0] - 1; j >= 0; --j) {
      if (cells[j * n + guards[i][1]] > 0) break;
      cells[j * n + guards[i][1]] = -1;
    }

    for (int j = guards[i][1] + 1; j < n; ++j) {
      if (cells[guards[i][0] * n + j] > 0) break;
      cells[guards[i][0] * n + j] = -1;
    }

    for (int j = guards[i][1] - 1; j >= 0; --j) {
      if (cells[guards[i][0] * n + j] > 0) break;
      cells[guards[i][0] * n + j] = -1;
    }
  }

  int unguarded = 0;
  for (int i = 0; i < m * n; ++i) {
    if (cells[i] == 0) ++unguarded;
  }

  return unguarded;
}
