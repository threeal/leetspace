int longestSubarray(int* nums, int numsSize) {
  int maxConsecutive = 0;
  int maxNum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < maxNum) continue;
    if (nums[i] > maxNum) {
      maxNum = nums[i];
      maxConsecutive = 1;
      for (++i; i < numsSize && nums[i] == maxNum; ++i) ++maxConsecutive;
      --i;
    } else {
      maxNum = nums[i];
      int consecutive = 1;
      for (++i; i < numsSize && nums[i] == maxNum; ++i) ++consecutive;
      if (consecutive > maxConsecutive) maxConsecutive = consecutive;
      --i;
    }
  }
  return maxConsecutive;
}
