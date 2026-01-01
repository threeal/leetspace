#include <stdbool.h>

bool hasTrailingZeros(int* nums, int numsSize) {
  return nums[numsSize - 1] == 0;
}
