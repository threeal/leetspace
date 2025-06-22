int minOperations(int* nums, int numsSize) {
  int prev = nums[0], sum = 0;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > prev) {
      prev = nums[i];
    } else {
      ++prev;
      sum += prev - nums[i];
    }
  }
  return sum;
}
