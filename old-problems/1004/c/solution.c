int longestOnes(int* nums, int numsSize, int k) {
  int maxLength = 0;
  for (int zeros = 0, l = 0, r = 0; r < numsSize; ++r) {
    if (nums[r] == 0) ++zeros;
    while (zeros > k) {
      if (nums[l] == 0) --zeros;
      ++l;
    }
    const int length = r + 1 - l;
    if (length > maxLength) maxLength = length;
  }
  return maxLength;
}
