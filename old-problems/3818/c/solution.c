int minimumPrefixLength(int* nums, int numsSize) {
  int i = numsSize - 1;
  while (i > 0 && nums[i - 1] < nums[i]) --i;
  return i;
}
