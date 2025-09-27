int longestSubarray(int* nums, int numsSize) {
  int i = 0;
  while (i < numsSize && nums[i] == 1) ++i;

  if (i == numsSize) return i - 1;

  int count = 0, maxCount = i, prev = i;
  while (++i < numsSize) {
    if (nums[i] == 0) {
      if (prev + count > maxCount) maxCount = prev + count;
      prev = count;
      count = 0;
    } else {
      ++count;
    }
  }

  return prev + count > maxCount ? prev + count : maxCount;
}
