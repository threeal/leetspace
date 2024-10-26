static int countSubsets(int* nums, int numsSize, int i, int max, int prev);

int countMaxOrSubsets(int* nums, int numsSize) {
  int max = 0;
  for (int i = 0; i < numsSize; ++i) max |= nums[i];
  return countSubsets(nums, numsSize, 0, max, 0);
}

static int countSubsets(int* nums, int numsSize, int i, int max, int prev) {
  if (i == numsSize) return 0;
  return ((prev | nums[i]) == max ? 1 : 0) +
      countSubsets(nums, numsSize, i + 1, max, prev | nums[i]) +
      countSubsets(nums, numsSize, i + 1, max, prev);
}
