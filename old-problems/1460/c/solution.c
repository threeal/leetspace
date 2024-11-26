#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
  qsort(target, targetSize, sizeof(int), compare);
  qsort(arr, arrSize, sizeof(int), compare);
  for (int i = 0; i < arrSize; ++i) {
    if (target[i] != arr[i]) return false;
  }
  return true;
}
