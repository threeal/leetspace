long long countSubarrays(int* nums, int numsSize, int k) {
  long long count = 0;

  int maxNum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > maxNum) maxNum = nums[i];
  }

  int left = 0;
  int right = 0;
  while (right < numsSize) {
    if (nums[right] == maxNum) --k;
    while (k <= 0) {
      if (nums[left] == maxNum) ++k;
      ++left;
    }
    count += left;
    ++right;
  }

  return count;
}
