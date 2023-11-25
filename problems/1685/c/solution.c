int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize) {
  int rightTotal = 0;
  for (int i = 0; i < numsSize; ++i) {
    rightTotal += nums[i];
  }

  int leftTotal = 0;
  for (int i = 0; i < numsSize; ++i) {
    leftTotal += nums[i];
    rightTotal -= nums[i];

    nums[i] = (nums[i] * (i + 1) - leftTotal) + (rightTotal - nums[i] * (numsSize - i - 1));
  }

  *returnSize = numsSize;
  return nums;
}
