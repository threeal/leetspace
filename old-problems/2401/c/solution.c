int longestNiceSubarray(int* nums, int numsSize) {
  int longest = 1, sum = nums[0];
  for (int l = 0, r = 1; r < numsSize; ++r) {
    while ((sum & nums[r]) != 0) {
      sum &= ~nums[l];
      ++l;
    }
    if (r - l + 1 > longest) longest = r - l + 1;
    sum |= nums[r];
  }
  return longest;
}
