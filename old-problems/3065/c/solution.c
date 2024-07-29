int minOperations(int* nums, int numsSize, int k) {
  int count = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] < k) ++count;
  }
  return count;
}
