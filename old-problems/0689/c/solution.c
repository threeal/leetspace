#include <stdlib.h>

int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
  int sum = 0;
  for (int i = 1; i < k; ++i) sum += nums[i];

  nums[0] += sum;
  for (int i = k; i < numsSize; ++i) {
    sum += nums[i];
    sum -= nums[i + 1 - k];
    nums[i + 1 - k] += sum;
  }

  const int indexesSize = numsSize - k;
  int* indexes = malloc(indexesSize * sizeof(int));
  int maxIndex = numsSize - 1;
  for (int i = indexesSize - 1; i >= 0; --i) {
    indexes[i] = maxIndex;
    if (nums[i + k - 1] >= nums[maxIndex]) maxIndex = i + k - 1;
  }

  maxIndex = indexesSize - 1;
  int maxSum = nums[maxIndex] + nums[indexes[maxIndex]];

  int a = maxIndex - k, b = maxIndex, c = indexes[maxIndex];
  for (int i = a - 1; i >= 0; --i) {
    const int sum = nums[i + k] + nums[indexes[i + k]];
    if (sum >= maxSum) {
      maxIndex = i + k;
      maxSum = sum;
    }

    if (nums[i] + maxSum >= nums[a] + nums[b] + nums[c]) {
      a = i;
      b = maxIndex;
      c = indexes[maxIndex];
    }
  }

  *returnSize = 3;
  int* returnData = malloc(*returnSize * sizeof(int));

  returnData[0] = a;
  returnData[1] = b;
  returnData[2] = c;

  return returnData;
}
