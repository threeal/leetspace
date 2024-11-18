int minimumSubarrayLength(int* nums, int numsSize, int k) {
  int l = 0, r = 0, n = numsSize + 1;

  int ans = nums[0];
  int bitCounts[33] = {0};
  for (int i = 0; (1 << i) <= nums[0]; ++i) {
    if ((1 << i & nums[0]) == 0) continue;
    ++bitCounts[i];
  }

  while (1) {
    if (ans >= k) {
      if (r - l + 1 < n) n = r - l + 1;
      if (l < r) {
        for (int i = 0; (1 << i) <= nums[l]; ++i) {
          if ((1 << i & nums[l]) == 0) continue;
          if (--bitCounts[i] == 0) ans = ans & ~(1 << i);
        }
        ++l;
        continue;
      }
    }

    if (++r >= numsSize) break;
    for (int i = 0; (1 << i) <= nums[r]; ++i) {
      if ((1 << i & nums[r]) == 0) continue;
      if (++bitCounts[i] == 1) ans = ans | (1 << i);
    }
  }

  return n <= numsSize ? n : -1;
}
