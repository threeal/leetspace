#include <stdlib.h>

struct cell_t {
  int height;
  int y;
  int x;
};

void cells_heap_push(struct cell_t* heap, int* size, struct cell_t cell) {
  int i = (*size)++;
  heap[i] = cell;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].height <= heap[i].height) break;

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

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
  const int my = heightMapSize, mx = heightMapColSize[0];

  struct cell_t* cells = malloc(my * mx * sizeof(struct cell_t));
  int cellsSize = 0;

  for (int i = 0; i < my; ++i) {
    cells_heap_push(cells, &cellsSize, (struct cell_t){heightMap[i][0], i, 0});
    heightMap[i][0] = -1;
  }

  if (mx > 1) {
    for (int i = 0; i < my; ++i) {
      cells_heap_push(
          cells, &cellsSize, (struct cell_t){heightMap[i][mx - 1], i, mx - 1});

      heightMap[i][mx - 1] = -1;
    }
  }

  for (int i = 1; i < mx - 1; ++i) {
    cells_heap_push(cells, &cellsSize, (struct cell_t){heightMap[0][i], 0, i});
    heightMap[0][i] = -1;
  }

  if (my > 1) {
    for (int i = 1; i < mx - 1; ++i) {
      cells_heap_push(
          cells, &cellsSize, (struct cell_t){heightMap[my - 1][i], my - 1, i});

      heightMap[my - 1][i] = -1;
    }
  }

  int volume = 0;
  while (cellsSize > 0) {
    const int height = cells[0].height;
    const int y = cells[0].y;
    const int x = cells[0].x;

    cells_heap_pop(cells, &cellsSize);

    if (y > 0 && heightMap[y - 1][x] >= 0) {
      if (height > heightMap[y - 1][x]) {
        volume += height - heightMap[y - 1][x];
        cells_heap_push(cells, &cellsSize, (struct cell_t){height, y - 1, x});
      } else {
        cells_heap_push(
            cells, &cellsSize, (struct cell_t){heightMap[y - 1][x], y - 1, x});
      }
      heightMap[y - 1][x] = -1;
    }

    if (y + 1 < my && heightMap[y + 1][x] >= 0) {
      if (height > heightMap[y + 1][x]) {
        volume += height - heightMap[y + 1][x];
        cells_heap_push(cells, &cellsSize, (struct cell_t){height, y + 1, x});
      } else {
        cells_heap_push(
            cells, &cellsSize, (struct cell_t){heightMap[y + 1][x], y + 1, x});
      }
      heightMap[y + 1][x] = -1;
    }

    if (x > 0 && heightMap[y][x - 1] >= 0) {
      if (height > heightMap[y][x - 1]) {
        volume += height - heightMap[y][x - 1];
        cells_heap_push(cells, &cellsSize, (struct cell_t){height, y, x - 1});
      } else {
        cells_heap_push(
            cells, &cellsSize, (struct cell_t){heightMap[y][x - 1], y, x - 1});
      }
      heightMap[y][x - 1] = -1;
    }

    if (x + 1 < mx && heightMap[y][x + 1] >= 0) {
      if (height > heightMap[y][x + 1]) {
        volume += height - heightMap[y][x + 1];
        cells_heap_push(cells, &cellsSize, (struct cell_t){height, y, x + 1});
      } else {
        cells_heap_push(
            cells, &cellsSize, (struct cell_t){heightMap[y][x + 1], y, x + 1});
      }
      heightMap[y][x + 1] = -1;
    }
  }

  return volume;
}
