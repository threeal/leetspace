#include <stdbool.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* binarySearch(int* left, int* right, int val) {
  while (left <= right) {
    int* mid = left + (right - left) / 2;
    if (*mid == val) return mid;
    if (*mid < val) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return NULL;
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
  if (handSize % groupSize != 0) return false;

  qsort(hand, handSize, sizeof(int), comp);

  for (int i = 0; i < handSize; i += groupSize) {
    int* begin = hand + i;
    int val = *begin + 1;
    *begin = -1;

    int* it = begin + 1;
    for (int i = groupSize - 1; i > 0; --i) {
      it = binarySearch(it, hand + handSize - 1, val);
      if (it == NULL) return false;
      *it = -1;
      ++it;
      ++val;
    }

    qsort(begin, it - begin, sizeof(int), comp);
  }

  return true;
}
