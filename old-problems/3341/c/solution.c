#include <stdlib.h>

struct cell_t {
  int time;
  int y;
  int x;
};

void cells_heap_push(struct cell_t* heap, int* size, struct cell_t* cell) {
  int i = (*size)++;
  heap[i] = *cell;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].time <= heap[i].time) break;

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
    if (left < *size && heap[left].time < heap[smallest].time) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right].time < heap[smallest].time) {
      smallest = right;
    }

    if (smallest == i) break;

    const struct cell_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
  const int ty = moveTimeSize - 1;
  const int tx = moveTimeColSize[ty] - 1;

  struct cell_t* heap = malloc((ty + 1) * (tx + 1) * sizeof(struct cell_t));
  int heapSize = 0;

  struct cell_t cell = {0, 0, 0};
  cells_heap_push(heap, &heapSize, &cell);
  moveTime[0][0] = -1;

  while (heapSize > 0) {
    const int time = heap[0].time;
    const int y = heap[0].y;
    const int x = heap[0].x;
    cells_heap_pop(heap, &heapSize);

    if (y > 0 && moveTime[y - 1][x] >= 0) {
      const int nextTime =
          (time >= moveTime[y - 1][x] ? time : moveTime[y - 1][x]) + 1;

      if (y - 1 == ty && x == tx) return nextTime;

      cell.time = nextTime;
      cell.y = y - 1;
      cell.x = x;
      cells_heap_push(heap, &heapSize, &cell);
      moveTime[y - 1][x] = -1;
    }

    if (y < ty && moveTime[y + 1][x] >= 0) {
      const int nextTime =
          (time >= moveTime[y + 1][x] ? time : moveTime[y + 1][x]) + 1;

      if (y + 1 == ty && x == tx) return nextTime;

      cell.time = nextTime;
      cell.y = y + 1;
      cell.x = x;
      cells_heap_push(heap, &heapSize, &cell);
      moveTime[y + 1][x] = -1;
    }

    if (x > 0 && moveTime[y][x - 1] >= 0) {
      const int nextTime =
          (time >= moveTime[y][x - 1] ? time : moveTime[y][x - 1]) + 1;

      if (y == ty && x - 1 == tx) return nextTime;

      cell.time = nextTime;
      cell.y = y;
      cell.x = x - 1;
      cells_heap_push(heap, &heapSize, &cell);
      moveTime[y][x - 1] = -1;
    }

    if (x < tx && moveTime[y][x + 1] >= 0) {
      const int nextTime =
          (time >= moveTime[y][x + 1] ? time : moveTime[y][x + 1]) + 1;

      if (y == ty && x + 1 == tx) return nextTime;

      cell.time = nextTime;
      cell.y = y;
      cell.x = x + 1;
      cells_heap_push(heap, &heapSize, &cell);
      moveTime[y][x + 1] = -1;
    }
  }

  return -1;
}
