#include <stdlib.h>

int* gPow2 = NULL;

int* generatePow2(void) {
  int* pow2 = malloc(100001 * sizeof(int));
  pow2[0] = 1;
  for (int i = 1; i < 100001; ++i) {
    pow2[i] = (pow2[i - 1] * 2) % 1000000007;
  }
  return pow2;
}

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int numSubseq(int* nums, int numsSize, int target) {
  int total = 0;

  if (gPow2 == NULL) gPow2 = generatePow2();
  qsort(nums, numsSize, sizeof(int), compare);

  int l = 0, r = numsSize;
  while (l < r) {
    if (nums[l] + nums[r - 1] <= target) {
      total = (total + gPow2[r - 1 - l]) % 1000000007;
      ++l;
    } else {
      --r;
    }
  }

  return total;
}
