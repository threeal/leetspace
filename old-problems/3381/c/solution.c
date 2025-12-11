#include <stdlib.h>

long long maxSubarraySum(int* nums, int numsSize, int k) {
  long long sum = 0;
  for (int i = 0; i < k; ++i) sum += nums[i];

  long long* prefixes = malloc(numsSize * sizeof(long long));
  for (int i = 0; i < numsSize; ++i) prefixes[i] = 0;

  prefixes[k - 1] = sum;
  long long maxSum = sum;

  for (int i = k; i < numsSize; ++i) {
    sum += nums[i] - nums[i - k];

    prefixes[i] = prefixes[i - k] > 0 ? sum + prefixes[i - k] : sum;
    if (prefixes[i] > maxSum) maxSum = prefixes[i];
  }

  return maxSum;
}
