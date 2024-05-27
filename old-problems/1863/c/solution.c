int subsetXORSum(int* nums, int numsSize) {
  int result = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    result |= nums[i];
  }
  return result << (numsSize - 1);
}
