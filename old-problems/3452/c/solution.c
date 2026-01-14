int sumOfGoodNumbers(int* nums, int numsSize, int k) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if ((i - k < 0 || nums[i] > nums[i - k]) &&
        (i + k >= numsSize || nums[i] > nums[i + k])) {
      sum += nums[i];
    }
  }
  return sum;
}
