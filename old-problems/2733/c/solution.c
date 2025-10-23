int findNonMinOrMax(int* nums, int numsSize) {
  int min = nums[0], max = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] < min) {
      if (min == max) {
        min = nums[i];
      } else {
        return min;
      }
    } else if (nums[i] > max) {
      if (min == max) {
        max = nums[i];
      } else {
        return max;
      }
    } else if (nums[i] > min && nums[i] < max) {
      return nums[i];
    }
  }
  return -1;
}
