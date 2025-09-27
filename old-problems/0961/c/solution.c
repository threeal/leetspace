#include <stdint.h>

int repeatedNTimes(int* nums, int numsSize) {
  uint8_t exists[10001 / 8] = {0};
  for (int i = 0; i < numsSize; ++i) {
    if ((exists[nums[i] / 8] & (1 << (nums[i] % 8))) != 0) {
      return nums[i];
    } else {
      exists[nums[i] / 8] |= 1 << (nums[i] % 8);
    }
  }
  return 0;
}
