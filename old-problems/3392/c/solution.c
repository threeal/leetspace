int countSubarrays(int* nums, int numsSize) {
  int count = 0;
  for (int i = 2; i < numsSize; ++i) {
    if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) ++count;
  }
  return count;
}
