int minOperations(int* nums, int numsSize) {
  int operations = 0;
  for (int i = 2; i < numsSize; ++i) {
    if (nums[i - 2] == 0) {
      ++operations;
      nums[i - 1] ^= 1;
      nums[i] ^= 1;
    }
  }

  return nums[numsSize - 1] == 1 && nums[numsSize - 2] == 1
      ? operations
      : -1;
}
