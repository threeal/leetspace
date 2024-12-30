int* getFinalState(
    int* nums, int numsSize, int k, int multiplier, int* returnSize) {
  while (k > 0) {
    int min = 0;
    for (int i = 1; i < numsSize; ++i) {
      if (nums[i] < nums[min]) min = i;
    }
    nums[min] *= multiplier;
    --k;
  }
  *returnSize = numsSize;
  return nums;
}
