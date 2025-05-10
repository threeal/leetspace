int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
  int rightSum = 0;
  for (int i = 0; i < numsSize; ++i) rightSum += nums[i];

  int leftSum = 0;
  for (int i = 0; i < numsSize; ++i) {
    const int temp = nums[i];
    rightSum -= temp;
    nums[i] = rightSum >= leftSum ? rightSum - leftSum : leftSum - rightSum;
    leftSum += temp;
  }

  *returnSize = numsSize;
  return nums;
}
