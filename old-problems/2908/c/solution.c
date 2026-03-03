#include <limits.h>
#include <stdlib.h>
#include <string.h>

int minimumSum(int* nums, int numsSize) {
  int* minNums = malloc(numsSize * sizeof(int));
  memcpy(minNums, nums, numsSize * sizeof(int));

  for (int i = numsSize - 1; i > 0; --i) {
    if (minNums[i] < minNums[i - 1]) minNums[i - 1] = minNums[i];
  }

  int minSum = INT_MAX, minNum = nums[0];
  for (int i = 2; i < numsSize; ++i) {
    if (nums[i - 1] > minNum && nums[i - 1] > minNums[i]) {
      const int sum = minNum + nums[i - 1] + minNums[i];
      if (sum < minSum) minSum = sum;
    }
    if (nums[i - 1] < minNum) minNum = nums[i - 1];
  }

  free(minNums);
  return minSum == INT_MAX ? -1 : minSum;
}
