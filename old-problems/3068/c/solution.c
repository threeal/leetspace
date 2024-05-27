#include <limits.h>

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
  (void)edges;
  (void)edgesSize;
  (void)edgesColSize;

  long long total = 0;
  int gainCount = 0;
  int minGain = INT_MAX;
  int minLoss = INT_MIN;
  for (int i = 0; i < numsSize; ++i) {
    total += nums[i];
    const int gain = (nums[i] ^ k) - nums[i];
    if (gain > 0) {
      total += gain;
      ++gainCount;
      if (gain < minGain) minGain = gain;
    } else {
      if (gain > minLoss) minLoss = gain;
    }
  }
  if (gainCount % 2 == 1) {
    total -= minLoss != INT_MIN
        ? (minGain < -minLoss ? minGain : -minLoss)
        : minGain;
  }
  return total;
}
