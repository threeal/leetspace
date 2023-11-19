// The solution can be done simply by sorting the array from lowest to highest
// and then iterating through the array following the rules so that the difference between each element should be equal to or less than 1.

#include <stdlib.h>

void mergeSort(int* begin, int* end);

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
  // Sort the array from the lowest to the highest.
  mergeSort(arr, arr + arrSize - 1);

  // Iterating through the elements for calculating the highest possible value.
  // The highest value is at the end of the array, but each next element should be capped if the difference is more than 1.
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
