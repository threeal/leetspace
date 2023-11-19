#include <stdlib.h>

void mergeSort(int* begin, int* end);

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
  // Sort the time required from lowest to highest (don't sort if already sorted).
  for (int i = 1; i < arrSize; ++i) {
    if (arr[i - 1] > arr[i]) {
      mergeSort(arr, arr + arrSize - 1);
      break;
    }
  }

  int res = 0;
  for (int i = 0; i < arrSize; ++i) {
    res = res + 1 < arr[i] ? res + 1 : arr[i];
  }

  return res;
}

// This function implements merge sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/merge-sort/
void mergeSort(int* begin, int* end) {
  if (begin >= end) return;

  int* mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid + 1, end);

  const int leftSize = mid - begin + 1;
  int* left = malloc(sizeof(int) * leftSize);
  for (int i = 0; i < leftSize; ++i) {
    left[i] = begin[i];
  }

  const int rightSize = end - mid;
  int* right = malloc(sizeof(int) * rightSize);
  for (int i = 0; i < rightSize; ++i) {
    right[i] = mid[i + 1];
  }

  int leftIdx = 0;
  int rightIdx = 0;
  int* it = begin;

  while (leftIdx < leftSize && rightIdx < rightSize) {
    if (left[leftIdx] <= right[rightIdx]) {
      *it = left[leftIdx];
      ++leftIdx;
    } else {
      *it = right[rightIdx];
      ++rightIdx;
    }
    ++it;
  }

  while (leftIdx < leftSize) {
    *it = left[leftIdx];
    ++leftIdx;
    ++it;
  }

  while (rightIdx < rightSize) {
    *it = right[rightIdx];
    ++rightIdx;
    ++it;
  }

  free(left);
  free(right);
}
