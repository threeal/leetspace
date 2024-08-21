#include <stdlib.h>

int differenceOfSum(int* nums, int numsSize) {
  int elementSum = 0;
  int digitSum = 0;

  for (int i = 0; i < numsSize; ++i) {
    elementSum += nums[i];
    while (nums[i] > 0) {
      digitSum += nums[i] % 10;
      nums[i] /= 10;
    }
  }

  return abs(elementSum - digitSum);
}
