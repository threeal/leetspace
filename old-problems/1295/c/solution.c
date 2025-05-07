int findNumbers(int* nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    if ((nums[i] >= 10 && nums[i] < 100) ||
        (nums[i] >= 1000 && nums[i] < 10000) ||
        nums[i] == 100000) {
      ++count;
    }
  }
  return count;
}
