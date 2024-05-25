int smallestRangeI(int* nums, int numsSize, int k) {
  int min = 10001;
  int max = -1;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] > max) max = nums[i];
    if (nums[i] < min) min = nums[i];
  }

  return max - min - k - k > 0 ? max - min - k - k : 0;
}
