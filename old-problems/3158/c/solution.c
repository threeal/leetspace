#include <stdbool.h>

int duplicateNumbersXOR(int* nums, int numsSize) {
  bool exists[51] = {false};
  int ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (exists[nums[i]]) {
      ans ^= nums[i];
    } else {
      exists[nums[i]] = true;
    }
  }
  return ans;
}
