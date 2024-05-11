#include <stdint.h>

int findMaxK(int* nums, int numsSize) {
  uint8_t exists[126] = {0};
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < 0) exists[-nums[i] / 8] |= 1 << -nums[i] % 8;
  }

  int largestNum = -1;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > 0 && (exists[nums[i] / 8] >> nums[i] % 8 & 1) && largestNum < nums[i]) largestNum = nums[i];
  }

  return largestNum;
}
