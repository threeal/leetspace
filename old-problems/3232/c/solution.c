#include <stdbool.h>

bool canAliceWin(int* nums, int numsSize) {
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < 10) {
      sum1 += nums[i];
    } else {
      sum2 += nums[i];
    }
  }
  return sum1 != sum2;
}
