#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return aa[0] == bb[0] ? bb[1] - aa[1] : aa[0] - bb[0];
}

int* maximumBeauty(
    int** items, int itemsSize, int* itemsColSize,
    int* queries, int queriesSize, int* returnSize) {
  (void)itemsColSize;

  qsort(items, itemsSize, sizeof(int*), compare);

  int maxBeauty = 0;
  for (int i = 0; i < itemsSize; ++i) {
    if (items[i][1] >= maxBeauty) {
      maxBeauty = items[i][1];
    } else {
      items[i][1] = maxBeauty;
    }
  }

  int* answers = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    int low = 1, high = itemsSize;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (items[itemsSize - mid][0] <= queries[i]) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }

    answers[i] = items[itemsSize - low][0] <= queries[i]
        ? items[itemsSize - low][1]
        : 0;
  }

  *returnSize = queriesSize;
  return answers;
}
