int numberOfArithmeticSlices(int* nums, int numsSize) {
  int count = 0, length = 1;
  for (int i = 2; i < numsSize; ++i) {
    if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
      count += length;
      ++length;
    } else {
      length = 1;
    }
  }
  return count;
}
