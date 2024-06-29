#include <stdlib.h>
#include <string.h>

int order[1001];

int comp(const void* a, const void* b) {
  if (order[*(int*)a] < 0) {
    if (order[*(int*)b] < 0) {
      return *(int*)a - *(int*)b;
    } else {
      return 1;
    }
  } else {
    if (order[*(int*)b] < 0) {
      return -1;
    } else {
      return order[*(int*)a] - order[*(int*)b];
    }
  }
}

int* relativeSortArray(
    int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
  memset(order, -1, 1001 * sizeof(int));
  for (int i = arr2Size - 1; i >= 0; --i) {
    order[arr2[i]] = i;
  }

  qsort(arr1, arr1Size, sizeof(int), comp);

  *returnSize = arr1Size;
  return arr1;
}
