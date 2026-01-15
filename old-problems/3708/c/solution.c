int longestSubarray(int* nums, int numsSize) {
  int length = 2, maxLength = 2;
  for (int i = 2; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1] + nums[i - 2]) {
      if (++length > maxLength) maxLength = length;
    } else {
      length = 2;
    }
  }
  return maxLength;
}
