#include <stdlib.h>

static void fill(int** grid, int y, int x, int width, int min);

int** specialGrid(int n, int* returnSize, int** returnColumnSizes) {
  int width = 1;
  while (n > 0) {
    width *= 2;
    --n;
  }

  int** output = malloc(width * sizeof(int*));
  int* outputColSize = malloc(width * sizeof(int));
  for (int i = 0; i < width; ++i) {
    output[i] = malloc(width * sizeof(int));
    outputColSize[i] = width;
  }

  if (width == 1) {
    output[0][0] = 0;
  } else {
    fill(output, 0, 0, width, 0);
  }

  *returnSize = width;
  *returnColumnSizes = outputColSize;
  return output;
}

static void fill(int** grid, int y, int x, int width, int min) {
  if (width == 2) {
    grid[y][x + 1] = min;
    grid[y + 1][x + 1] = min + 1;
    grid[y + 1][x] = min + 2;
    grid[y][x] = min + 3;
  } else {
    const int half = width / 2;
    const int area = half * half;
    fill(grid, y, x + half, half, min);
    fill(grid, y + half, x + half, half, min + area);
    fill(grid, y + half, x, half, min + 2 * area);
    fill(grid, y, x, half, min + 3 * area);
  }
}
