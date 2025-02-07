int longestMonotonicSubarray(int* nums, int numsSize) {
  int longest = 1;
  for (int l1 = 0, l2 = 0, r = 1; r < numsSize; ++r) {
    if (nums[r] <= nums[r - 1]) {
      l1 = r;
    } else if (r - l1 + 1 > longest) {
      longest = r - l1 + 1;
    }

    if (nums[r] >= nums[r - 1]) {
      l2 = r;
    } else if (r - l2 + 1 > longest) {
      longest = r - l2 + 1;
    }
  }
  return longest;
}
