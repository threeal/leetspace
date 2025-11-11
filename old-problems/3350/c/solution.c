int maxIncreasingSubarrays(int* nums, int numsSize) {
  int maxLen = 0, prevLen = 0, l = 0;
  for (int r = 1; r < numsSize; ++r) {
    if (nums[r] <= nums[r - 1]) {
      const int len = r - l;
      if (len / 2 > maxLen) maxLen = len / 2;

      const int minLen = len < prevLen ? len : prevLen;
      if (minLen > maxLen) maxLen = minLen;

      prevLen = len;
      l = r;
    }
  }

  const int len = numsSize - l;
  if (len / 2 > maxLen) maxLen = len / 2;

  const int minLen = len < prevLen ? len : prevLen;
  if (minLen > maxLen) maxLen = minLen;

  return maxLen;
}
