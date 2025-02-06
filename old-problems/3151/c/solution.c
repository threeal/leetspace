#include <stdbool.h>

bool isArraySpecial(int* nums, int numsSize) {
  return nums[numsSize - 1] == 0;
}
