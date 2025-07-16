#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int countDistinctIntegers(int* nums, int numsSize) {
  int* nums2 = malloc(numsSize * 2 * sizeof(int));
  memcpy(nums2, nums, numsSize * sizeof(int));
  int nums2Size = numsSize;

  for (int i = 0; i < numsSize; ++i) {
    int num = nums2[i], rnum = 0;
    while (num > 0) {
      rnum = rnum * 10 + num % 10;
      num /= 10;
    }
    nums2[nums2Size++] = rnum;
  }

  qsort(nums2, nums2Size, sizeof(int), compare);

  int count = 1;
  for (int i = 1; i < nums2Size; ++i) {
    if (nums2[i] != nums2[i - 1]) ++count;
  }

  return count;
}
