int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;
  int* bn = nums + numsSize - 1;
  int* an = bn - 1;
  for (int* a = nums; a <= an; ++a) {
    for (int* b = a + 1; b <= bn; ++b) {
      if (*a + *b == target) {
        nums[0] = a - nums;
        nums[1] = b - nums;
        return nums;
      }
    }
  }
  return nums;
}
