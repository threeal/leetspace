#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

struct cell_t {
  int y;
  int x;
};

static void setVisited(uint64_t* visited, int rows, int y, int x) {
  if (x < 64) {
    visited[y] |= (uint64_t)1 << x;
  } else {
    visited[rows + y] |= (uint64_t)1 << (x - 64);
  }
}

static bool getVisited(uint64_t* visited, int rows, int y, int x) {
  return x < 64
      ? (visited[y] & ((uint64_t)1 << x)) != 0
      : (visited[rows + y] & ((uint64_t)1 << (x - 64))) != 0;
}

int** allCellsDistOrder(
    int rows, int cols, int rCenter, int cCenter,
    int* returnSize, int** returnColumnSizes) {
  int** output = malloc(rows * cols * sizeof(int*));
  int* outputColSizes = malloc(rows * cols * sizeof(int));
  int outputSize = 0;

  struct cell_t* cells = malloc(rows * cols * sizeof(struct cell_t));
  int cellsBack = 0;
  int cellsFront = 0;

  uint64_t* visited = malloc(rows * 2 * sizeof(uint64_t));
  memset(visited, 0, rows * 2 * sizeof(uint64_t));

  cells[cellsBack].y = rCenter;
  cells[cellsBack].x = cCenter;
  ++cellsBack;

  setVisited(visited, rows, rCenter, cCenter);

  while (cellsFront < cellsBack) {
    const int y = cells[cellsFront].y;
    const int x = cells[cellsFront].x;
    ++cellsFront;

    output[outputSize] = malloc(2 * sizeof(int));
    output[outputSize][0] = y;
    output[outputSize][1] = x;
    outputColSizes[outputSize] = 2;
    ++outputSize;

    if (y > 0 && !getVisited(visited, rows, y - 1, x)) {
      cells[cellsBack].y = y - 1;
      cells[cellsBack].x = x;
      ++cellsBack;

      setVisited(visited, rows, y - 1, x);
    }

    if (y + 1 < rows && !getVisited(visited, rows, y + 1, x)) {
      cells[cellsBack].y = y + 1;
      cells[cellsBack].x = x;
      ++cellsBack;

      setVisited(visited, rows, y + 1, x);
    }

    if (x > 0 && !getVisited(visited, rows, y, x - 1)) {
      cells[cellsBack].y = y;
      cells[cellsBack].x = x - 1;
      ++cellsBack;

      setVisited(visited, rows, y, x - 1);
    }

    if (x + 1 < cols && !getVisited(visited, rows, y, x + 1)) {
      cells[cellsBack].y = y;
      cells[cellsBack].x = x + 1;
      ++cellsBack;

      setVisited(visited, rows, y, x + 1);
    }
  }

  free(cells);
  free(visited);

  *returnSize = outputSize;
  *returnColumnSizes = outputColSizes;
  return output;
}
