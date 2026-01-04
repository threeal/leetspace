#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findTheDistanceValue(
    int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
  qsort(arr2, arr2Size, sizeof(int), compare);

  int count = 0;
  for (int i = 0; i < arr1Size; ++i) {
    int low1 = 0, high1 = arr2Size;
    while (low1 < high1) {
      const int mid = low1 + (high1 - low1) / 2;
      if (arr2[mid] < arr1[i] - d) {
        low1 = mid + 1;
      } else {
        high1 = mid;
      }
    }

    int low2 = 0, high2 = arr2Size;
    while (low2 < high2) {
      const int mid = low2 + (high2 - low2) / 2;
      if (arr2[mid] <= arr1[i] + d) {
        low2 = mid + 1;
      } else {
        high2 = mid;
      }
    }

    if (low1 == low2) ++count;
  }

  return count;
}
