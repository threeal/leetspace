#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {
  (void)eventsColSize;

  qsort(events, eventsSize, sizeof(int*), compare);

  int* eventMaxs = malloc(eventsSize * sizeof(int));
  eventMaxs[eventsSize - 1] = events[eventsSize - 1][2];

  for (int i = eventsSize - 1; i > 0; --i) {
    eventMaxs[i - 1] =
        events[i - 1][2] > eventMaxs[i] ? events[i - 1][2] : eventMaxs[i];
  }

  int maxSum = 0;
  for (int i = 0; i < eventsSize; ++i) {
    int low = i + 1, high = eventsSize - 1;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (events[mid][0] <= events[i][1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    const int sum = events[high][0] > events[i][1]
        ? events[i][2] + eventMaxs[high]
        : events[i][2];

    if (sum > maxSum) maxSum = sum;
  }

  free(eventMaxs);

  return maxSum;
}
