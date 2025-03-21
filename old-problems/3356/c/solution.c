#include <stdbool.h>

static bool verify(int* nums, int numsSize, int** queries, int k);

static int sums[100001];

int minZeroArray(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize) {
  (void)queriesColSize;

  int low = 0, high = queriesSize;
  while (low < high) {
    const int mid = low + (high - low) / 2;
    if (verify(nums, numsSize, queries, mid)) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return verify(nums, numsSize, queries, low) ? low : -1;
}

static bool verify(int* nums, int numsSize, int** queries, int k) {
  for (int i = 0; i <= numsSize; ++i) sums[i] = 0;

  for (int i = 0; i < k; ++i) {
    sums[queries[i][0]] += queries[i][2];
    sums[queries[i][1] + 1] -= queries[i][2];
  }

  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += sums[i];
    if (nums[i] > sum) return false;
  }

  return true;
}
