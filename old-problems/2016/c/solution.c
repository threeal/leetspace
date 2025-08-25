int maximumDifference(int* nums, int numsSize) {
  int diff = -1, min = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] == min) continue;
    if (nums[i] < min) {
      min = nums[i];
    } else if (nums[i] - min > diff) {
      diff = nums[i] - min;
    }
  }
  return diff;
}
