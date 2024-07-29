#include <stdlib.h>
#include <string.h>

void mergeSort(int* temp, int* low, int* high);

int* sortArray(int* nums, int numsSize, int* returnSize) {
  int* temp = malloc(numsSize * sizeof(int));
  mergeSort(temp, nums, nums + numsSize - 1);
  free(temp);

  *returnSize = numsSize;
  return nums;
}

void mergeSort(int* temp, int* low, int* high) {
  if (low >= high) return;

  int* mid = low + (high - low) / 2;

  mergeSort(temp, low, mid);
  mergeSort(temp, mid + 1, high);

  memcpy(temp, low, (high - low + 1) * sizeof(int));
  int* tempMid = temp + (mid - low);
  int* tempHigh = temp + (high - low);

  int* outIt = low;

  int* loIt = temp;
  int* hiIt = tempMid + 1;

  while (loIt <= tempMid && hiIt <= tempHigh) {
    if (*loIt <= *hiIt) {
      *outIt = *loIt;
      ++loIt;
    } else {
      *outIt = *hiIt;
      ++hiIt;
    }
    ++outIt;
  }

  if (loIt <= tempMid) {
    memcpy(outIt, loIt, (tempMid - loIt + 1) * sizeof(int));
  } else if (hiIt <= tempHigh) {
    memcpy(outIt, hiIt, (tempHigh - hiIt + 1) * sizeof(int));
  }
}
