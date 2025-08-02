#include <stdbool.h>

int sumCounts(int* nums, int numsSize) {
  int sum = numsSize;
  for (int i = 0; i < numsSize; ++i) {
    bool exists[101] = {false};
    exists[nums[i]] = true;

    int distinct = 1;
    for (int j = i + 1; j < numsSize; ++j) {
      if (!exists[nums[j]]) {
        exists[nums[j]] = true;
        ++distinct;
      }
      sum += distinct * distinct;
    }
  }
  return sum;
}
