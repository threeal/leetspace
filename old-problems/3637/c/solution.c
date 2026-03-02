#include <stdbool.h>

bool isTrionic(int* nums, int numsSize) {
  if (nums[1] <= nums[0]) return false;

  int i = 2;
  while (i < numsSize && nums[i - 1] < nums[i]) ++i;
  if (i == numsSize || nums[i - 1] == nums[i]) return false;

  while (i < numsSize && nums[i - 1] > nums[i]) ++i;
  if (i == numsSize || nums[i - 1] == nums[i]) return false;

  while (i < numsSize && nums[i - 1] < nums[i]) ++i;
  return i == numsSize;
}
