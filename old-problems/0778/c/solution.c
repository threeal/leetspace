#include <stdlib.h>

struct cell_t {
  int height;
  int y;
  int x;
};

void cellsHeapPush(struct cell_t* heap, int* size, struct cell_t* move) {
  int i = (*size)++;
  heap[i] = *move;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].height <= heap[i].height) break;

    const struct cell_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void cellsHeapPop(struct cell_t* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left].height < heap[smallest].height) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right].height < heap[smallest].height) {
      smallest = right;
    }

    if (smallest == i) break;

    const struct cell_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int swimInWater(int** grid, int gridSize, int* gridColSize) {
  struct cell_t* cellsHeap = malloc(
      gridSize * gridColSize[0] * sizeof(struct cell_t));
  int cellsSize = 0;

  int maxHeight = grid[0][0];

  struct cell_t cell = {grid[0][0], 0, 0};
  cellsHeapPush(cellsHeap, &cellsSize, &cell);

  grid[0][0] = -1;

  while (cellsSize != 0) {
    const int height = cellsHeap[0].height;
    const int y = cellsHeap[0].y;
    const int x = cellsHeap[0].x;

    if (height > maxHeight) maxHeight = height;
    if (y == gridSize - 1 && x == gridColSize[y] - 1) break;

    cellsHeapPop(cellsHeap, &cellsSize);

    if (y > 0 && grid[y - 1][x] >= 0) {
      cell.height = grid[y - 1][x];
      cell.y = y - 1;
      cell.x = x;

      cellsHeapPush(cellsHeap, &cellsSize, &cell);
      grid[y - 1][x] = -1;
    }

    if (x > 0 && grid[y][x - 1] >= 0) {
      cell.height = grid[y][x - 1];
      cell.y = y;
      cell.x = x - 1;

      cellsHeapPush(cellsHeap, &cellsSize, &cell);
      grid[y][x - 1] = -1;
    }

    if (y + 1 < gridSize && grid[y + 1][x] >= 0) {
      cell.height = grid[y + 1][x];
      cell.y = y + 1;
      cell.x = x;

      cellsHeapPush(cellsHeap, &cellsSize, &cell);
      grid[y + 1][x] = -1;
    }

    if (x + 1 < gridColSize[y] && grid[y][x + 1] >= 0) {
      cell.height = grid[y][x + 1];
      cell.y = y;
      cell.x = x + 1;

      cellsHeapPush(cellsHeap, &cellsSize, &cell);
      grid[y][x + 1] = -1;
    }
  }

  return maxHeight;
}
