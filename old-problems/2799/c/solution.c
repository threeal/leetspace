int countCompleteSubarrays(int* nums, int numsSize) {
  int totalDistinct = 0, freqs[2001] = {0};
  for (int i = 0; i < numsSize; ++i) {
    if (++freqs[nums[i]] == 1) ++totalDistinct;
  }

  for (int i = 0; i < numsSize; ++i) --freqs[nums[i]];

  int count = 0, distinct = 0, l = 0, r = 0;
  while (1) {
    while (r < numsSize && distinct < totalDistinct) {
      if (++freqs[nums[r]] == 1) ++distinct;
      ++r;
    }

    if (distinct != totalDistinct) break;
    count += numsSize - r + 1;

    if (--freqs[nums[l]] == 0) --distinct;
    ++l;
  }

  return count;
}
