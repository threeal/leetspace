int longestSubarray(int* nums, int numsSize) {
  int consecutive = 0, maxConsecutive = 0, maxNum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < maxNum) {
      consecutive = 0;
    } else if (nums[i] > maxNum) {
      consecutive = 1;
      maxConsecutive = 1;
      maxNum = nums[i];
    } else {
      ++consecutive;
      if (consecutive > maxConsecutive) {
        maxConsecutive = consecutive;
      }
    }
  }
  return maxConsecutive;
}
