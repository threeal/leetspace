#include <stdlib.h>

struct move_t {
  int time;
  int y;
  int x;
};

void movesHeapPush(struct move_t* heap, int* size, struct move_t* move) {
  int i = (*size)++;
  heap[i] = *move;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].time <= heap[i].time) break;

    const struct move_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void movesHeapPop(struct move_t* heap, int* size) {
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

    const struct move_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
  const int ty = moveTimeSize - 1;
  const int tx = moveTimeColSize[ty] - 1;

  struct move_t* movesHeap = malloc(
      moveTimeSize * moveTimeColSize[0] * sizeof(struct move_t));
  int movesSize = 0;

  struct move_t move = {0, 0, 0};
  movesHeapPush(movesHeap, &movesSize, &move);
  moveTime[0][0] = -1;

  while (movesSize > 0) {
    const int time = movesHeap[0].time;
    const int y = movesHeap[0].y;
    const int x = movesHeap[0].x;
    const int speed = (y % 2 == x % 2) ? 1 : 2;
    movesHeapPop(movesHeap, &movesSize);

    if (y > 0 && moveTime[y - 1][x] >= 0) {
      const int nextTime =
          (time >= moveTime[y - 1][x] ? time : moveTime[y - 1][x]) + speed;
      if (y - 1 == ty && x == tx) return nextTime;
      move.time = nextTime;
      move.y = y - 1;
      move.x = x;
      movesHeapPush(movesHeap, &movesSize, &move);
      moveTime[y - 1][x] = -1;
    }

    if (y < ty && moveTime[y + 1][x] >= 0) {
      const int nextTime =
          (time >= moveTime[y + 1][x] ? time : moveTime[y + 1][x]) + speed;
      if (y + 1 == ty && x == tx) return nextTime;
      move.time = nextTime;
      move.y = y + 1;
      move.x = x;
      movesHeapPush(movesHeap, &movesSize, &move);
      moveTime[y + 1][x] = -1;
    }

    if (x > 0 && moveTime[y][x - 1] >= 0) {
      const int nextTime =
          (time >= moveTime[y][x - 1] ? time : moveTime[y][x - 1]) + speed;
      if (y == ty && x - 1 == tx) return nextTime;
      move.time = nextTime;
      move.y = y;
      move.x = x - 1;
      movesHeapPush(movesHeap, &movesSize, &move);
      moveTime[y][x - 1] = -1;
    }

    if (x < tx && moveTime[y][x + 1] >= 0) {
      const int nextTime =
          (time >= moveTime[y][x + 1] ? time : moveTime[y][x + 1]) + speed;
      if (y == ty && x + 1 == tx) return nextTime;
      move.time = nextTime;
      move.y = y;
      move.x = x + 1;
      movesHeapPush(movesHeap, &movesSize, &move);
      moveTime[y][x + 1] = -1;
    }
  }

  return -1;
}
