#include <stdlib.h>

int compare(const void* a, const void* b) {
  return **(int**)a - **(int**)b;
}

void heap_push(int* heap, int* size, int val) {
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

void heap_pop(int* heap, int* size) {
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

int maxEvents(int** events, int eventsSize, int* eventsColSize) {
  (void)eventsColSize;

  qsort(events, eventsSize, sizeof(int*), compare);

  int count = 0;
  int day = 0;
  int eventsI = 0;

  int* eventEnds = malloc(eventsSize * sizeof(int));
  int eventEndsSize = 0;

  while (eventsI < eventsSize || eventEndsSize != 0) {
    if (eventEndsSize == 0 && day < events[eventsI][0]) {
      day = events[eventsI][0];
    }

    while (eventsI < eventsSize && events[eventsI][0] == day) {
      heap_push(eventEnds, &eventEndsSize, events[eventsI][1]);
      ++eventsI;
    }

    heap_pop(eventEnds, &eventEndsSize);
    ++count;
    ++day;

    while (eventEndsSize != 0 && eventEnds[0] < day) {
      heap_pop(eventEnds, &eventEndsSize);
    }
  }

  free(eventEnds);
  return count;
}
