#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] == (*(int**)b)[0]
      ? (*(int**)a)[1] - (*(int**)b)[1]
      : (*(int**)a)[0] - (*(int**)b)[0];
}

void heapPush(int* heap, int* size, int val) {
  int i = (*size)++;
  heap[i] = val;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent] <= heap[i]) break;

    const int temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void heapPop(int* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left] < heap[smallest]) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right] < heap[smallest]) {
      smallest = right;
    }

    if (smallest == i) break;

    const int temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

struct used_room_t {
  long long endTime;
  int id;
};

void usedRoomHeapPush(
    struct used_room_t* heap, int* size, struct used_room_t* room) {
  int i = (*size)++;
  heap[i] = *room;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].endTime == heap[i].endTime) {
      if (heap[parent].id <= heap[i].id) break;
    } else {
      if (heap[parent].endTime <= heap[i].endTime) break;
    }

    const struct used_room_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

void usedRoomHeapPop(struct used_room_t* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size) {
      if (heap[left].endTime == heap[smallest].endTime) {
        if (heap[left].id < heap[smallest].id) {
          smallest = left;
        }
      } else {
        if (heap[left].endTime < heap[smallest].endTime) {
          smallest = left;
        }
      }
    }

    const int right = 2 * i + 2;
    if (right < *size) {
      if (heap[right].endTime == heap[smallest].endTime) {
        if (heap[right].id < heap[smallest].id) {
          smallest = right;
        }
      } else {
        if (heap[right].endTime < heap[smallest].endTime) {
          smallest = right;
        }
      }
    }

    if (smallest == i) break;

    const struct used_room_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
  (void)meetingsColSize;

  qsort(meetings, meetingsSize, sizeof(int*), compare);

  int* roomsAvailable = malloc(n * sizeof(int));
  int roomsAvailableSize = 0;

  for (int i = 0; i < n; ++i) {
    heapPush(roomsAvailable, &roomsAvailableSize, i);
  }

  struct used_room_t* roomsUsed = malloc(n * sizeof(struct used_room_t));
  int roomsUsedSize = 0;

  int* roomsCount = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) roomsCount[i] = 0;

  for (int i = 0; i < meetingsSize; ++i) {
    while (roomsUsedSize > 0 && roomsUsed[0].endTime <= meetings[i][0]) {
      heapPush(roomsAvailable, &roomsAvailableSize, roomsUsed[0].id);
      usedRoomHeapPop(roomsUsed, &roomsUsedSize);
    }

    if (roomsAvailableSize == 0) {
      struct used_room_t room = roomsUsed[0];
      usedRoomHeapPop(roomsUsed, &roomsUsedSize);

      ++roomsCount[room.id];
      room.endTime = room.endTime + meetings[i][1] - meetings[i][0];
      usedRoomHeapPush(roomsUsed, &roomsUsedSize, &room);
    } else {
      ++roomsCount[roomsAvailable[0]];
      struct used_room_t room = {meetings[i][1], roomsAvailable[0]};
      usedRoomHeapPush(roomsUsed, &roomsUsedSize, &room);
      heapPop(roomsAvailable, &roomsAvailableSize);
    }
  }

  int room = 0, roomCount = roomsCount[0];
  for (int i = 1; i < n; ++i) {
    if (roomsCount[i] > roomCount) {
      room = i;
      roomCount = roomsCount[i];
    }
  }

  free(roomsAvailable);
  free(roomsUsed);
  free(roomsCount);

  return room;
}
