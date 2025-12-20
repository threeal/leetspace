int findKOr(int* nums, int numsSize, int k) {
  int freqs[32] = {0};
  for (int i = 0; i < numsSize; ++i) {
    int num = nums[i];
    for (int j = 0; num != 0; ++j) {
      if ((num & 1) != 0) ++freqs[j];
      num >>= 1;
    }
  }

  int num = 0;
  for (int i = 0; i < 32; ++i) {
    if (freqs[i] >= k) num |= 1 << i;
  }

  return num;
}
