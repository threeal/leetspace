#include <stdbool.h>

bool isZeroArray(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize) {
  (void)queriesColSize;

  for (int i = numsSize - 1; i > 0; --i) {
    nums[i] -= nums[i - 1];
  }

  for (int i = 0; i < queriesSize; ++i) {
    --nums[queries[i][0]];
    if (queries[i][1] + 1 < numsSize) ++nums[queries[i][1] + 1];
  }

  int num = 0;
  for (int i = 0; i < numsSize; ++i) {
    num += nums[i];
    if (num > 0) return false;
  }

  return true;
}
