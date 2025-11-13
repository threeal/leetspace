int maximumStrongPairXor(int* nums, int numsSize) {
  int max = 0;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i; j < numsSize; ++j) {
      const int diff = nums[j] >= nums[i] ? nums[j] - nums[i] : nums[i] - nums[j];
      const int min = nums[i] <= nums[j] ? nums[i] : nums[j];
      if (diff <= min && (nums[i] ^ nums[j]) > max) {
        max = nums[i] ^ nums[j];
      }
    }
  }
  return max;
}
