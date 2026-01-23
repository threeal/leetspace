#include <stdlib.h>

int gColSize;
int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  for (int i = 0; i < gColSize; ++i) {
    if (aa[i] != bb[i]) return aa[i] - bb[i];
  }
  return 0;
}

int equalPairs(int** grid, int gridSize, int* gridColSize) {
  int** rows = malloc(gridSize * sizeof(int*));
  for (int i = 0; i < gridSize; ++i) rows[i] = grid[i];

  gColSize = gridColSize[0];
  qsort(rows, gridSize, sizeof(int*), compare);

  int rowsSize = 1;
  int* rowFreqs = malloc(gridSize * sizeof(int));
  rowFreqs[0] = 1;

  for (int i = 1; i < gridSize; ++i) {
    if (compare(rows + rowsSize - 1, rows + i) == 0) {
      ++rowFreqs[rowsSize - 1];
    } else {
      rows[rowsSize] = rows[i];
      rowFreqs[rowsSize] = 1;
      ++rowsSize;
    }
  }

  int count = 0;
  int* column = malloc(gridSize * sizeof(int));
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridSize; ++j) {
      column[j] = grid[j][i];
    }

    int low = 0, high = rowsSize - 1;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      int res = compare(rows + mid, &column);
      if (res < 0) {
        low = mid + 1;
      } else if (res > 0) {
        high = mid;
      } else {
        count += rowFreqs[mid];
        break;
      }
    }

    if (low >= high && compare(rows + low, &column) == 0) {
      count += rowFreqs[low];
    }
  }

  free(rows);
  free(rowFreqs);
  free(column);

  return count;
}
