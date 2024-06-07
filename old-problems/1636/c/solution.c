#include <stdlib.h>
#include <string.h>

int frequencies[201];
int* frequenciesCenter = frequencies + 100;

int comp(const void* a, const void* b) {
  const int freqa = frequenciesCenter[*(int*)a];
  const int freqb = frequenciesCenter[*(int*)b];
  return freqa == freqb ? *(int*)b - *(int*)a : freqa - freqb;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
  memset(frequencies, 0, 201 * sizeof(int));

  for (int i = numsSize - 1; i >= 0; --i) {
    ++frequenciesCenter[nums[i]];
  }

  qsort(nums, numsSize, sizeof(int), comp);

  *returnSize = numsSize;
  return nums;
}
