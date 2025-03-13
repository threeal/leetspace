#include <stdbool.h>
#include <string.h>

int* findMissingAndRepeatedValues(
    int** grid, int gridSize, int* gridColSize, int* returnSize) {
  const int n = gridSize * gridSize;

  static bool exists[50 * 50 + 1];
  memset(exists, false, (n + 1) * sizeof(bool));

  int repeated = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (exists[grid[i][j]]) {
        repeated = grid[i][j];
      } else {
        exists[grid[i][j]] = true;
      }
    }
  }

  int missing = 0;
  for (int val = 1; val <= n; ++val) {
    if (!exists[val]) {
      missing = val;
      break;
    }
  }

  static int output[2];

  output[0] = repeated;
  output[1] = missing;

  *returnSize = 2;
  return output;
}
