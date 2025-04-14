#include <stdbool.h>

int minOperations(int* nums, int numsSize, int k) {
  bool exists[101] = {false};
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < k) return -1;
    if (!exists[nums[i]]) {
      exists[nums[i]] = true;
      ++count;
    }
  }
  if (exists[k]) --count;
  return count;
}
