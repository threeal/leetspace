#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

struct prev_event_t {
  int endDay;
  int sum;
};

static void pairs_heap_push(
    struct prev_event_t* heap, int* size, struct prev_event_t* prevEvent) {
  int i = (*size)++;
  heap[i] = *prevEvent;

  while (i > 0) {
    int parent = (i - 1) / 2;
    if (heap[parent].endDay <= heap[i].endDay) break;

    const struct prev_event_t temp = heap[parent];
    heap[parent] = heap[i];
    heap[i] = temp;

    i = parent;
  }
}

static void pairs_heap_pop(struct prev_event_t* heap, int* size) {
  heap[0] = heap[--(*size)];

  int i = 0;
  while (1) {
    int smallest = i;

    const int left = 2 * i + 1;
    if (left < *size && heap[left].endDay < heap[smallest].endDay) {
      smallest = left;
    }

    const int right = 2 * i + 2;
    if (right < *size && heap[right].endDay < heap[smallest].endDay) {
      smallest = right;
    }

    if (smallest == i) break;

    const struct prev_event_t temp = heap[smallest];
    heap[smallest] = heap[i];
    heap[i] = temp;

    i = smallest;
  }
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
  (void)eventsColSize;

  qsort(events, eventsSize, sizeof(int*), compare);

  int* sums = malloc(eventsSize * sizeof(int));
  for (int i = 0; i < eventsSize; ++i) {
    sums[i] = events[i][2];
  }

  struct prev_event_t* prevEvents = malloc(
      eventsSize * sizeof(struct prev_event_t));

  while (--k > 0) {
    int maxPrevSum = 0, prevEventsSize = 0;
    for (int i = 0; i < eventsSize; ++i) {
      while (prevEventsSize > 0) {
        if (prevEvents[0].endDay < events[i][0]) {
          if (prevEvents[0].sum > maxPrevSum) maxPrevSum = prevEvents[0].sum;
          pairs_heap_pop(prevEvents, &prevEventsSize);
        } else {
          break;
        }
      }

      struct prev_event_t prevEvent = {events[i][1], sums[i]};
      pairs_heap_push(prevEvents, &prevEventsSize, &prevEvent);

      sums[i] = events[i][2] + maxPrevSum;
    }
  }

  free(prevEvents);

  int max = 0;
  for (int i = 0; i < eventsSize; ++i) {
    if (sums[i] > max) max = sums[i];
  }

  free(sums);

  return max;
}
