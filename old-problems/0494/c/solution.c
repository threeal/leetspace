int findTargetSumWays(int* nums, int numsSize, int target) {
  if (numsSize == 0) return target == 0 ? 1 : 0;
  return findTargetSumWays(nums + 1, numsSize - 1, target + nums[0]) +
      findTargetSumWays(nums + 1, numsSize - 1, target - nums[0]);
}
