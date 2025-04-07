#include <stdlib.h>

struct cell_t {
  int value;
  int y;
  int x;
};

void cells_heap_push(struct cell_t* heap, int* size, struct cell_t* cell) {
  int i = (*size)++;
  heap[i] = *cell;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].value <= heap[i].value) break;

    const struct cell_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void cells_heap_pop(struct cell_t* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left].value < heap[smallest].value) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right].value < heap[smallest].value) {
      smallest = right;
    }

    if (smallest == i) break;

    const struct cell_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int* nums;
int compareIndexOfNum(const void* a, const void* b) {
  return nums[*(int*)a] - nums[*(int*)b];
}

int* maxPoints(
    int** grid, int gridSize, int* gridColSize,
    int* queries, int queriesSize, int* returnSize) {
  int* indices = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) indices[i] = i;

  nums = queries;
  qsort(indices, queriesSize, sizeof(int), compareIndexOfNum);

  int count = 0;

  struct cell_t* cells_heap = malloc(gridSize * gridColSize[0] * sizeof(struct cell_t));
  int cells_size = 0;

  struct cell_t cell = {grid[0][0], 0, 0};
  cells_heap_push(cells_heap, &cells_size, &cell);
  grid[0][0] = 0;

  for (int i = 0; i < queriesSize; ++i) {
    while (cells_size != 0 && cells_heap[0].value < queries[indices[i]]) {
      ++count;

      const int y = cells_heap[0].y;
      const int x = cells_heap[0].x;
      cells_heap_pop(cells_heap, &cells_size);

      if (y > 0 && grid[y - 1][x] > 0) {
        cell.value = grid[y - 1][x];
        cell.y = y - 1;
        cell.x = x;
        cells_heap_push(cells_heap, &cells_size, &cell);
        grid[y - 1][x] = 0;
      }

      if (x > 0 && grid[y][x - 1] > 0) {
        cell.value = grid[y][x - 1];
        cell.y = y;
        cell.x = x - 1;
        cells_heap_push(cells_heap, &cells_size, &cell);
        grid[y][x - 1] = 0;
      }

      if (y < gridSize - 1 && grid[y + 1][x] > 0) {
        cell.value = grid[y + 1][x];
        cell.y = y + 1;
        cell.x = x;
        cells_heap_push(cells_heap, &cells_size, &cell);
        grid[y + 1][x] = 0;
      }

      if (x < gridColSize[y] - 1 && grid[y][x + 1] > 0) {
        cell.value = grid[y][x + 1];
        cell.y = y;
        cell.x = x + 1;
        cells_heap_push(cells_heap, &cells_size, &cell);
        grid[y][x + 1] = 0;
      }
    }
    queries[indices[i]] = count;
  }

  free(cells_heap);
  free(indices);

  *returnSize = queriesSize;
  return queries;
}
