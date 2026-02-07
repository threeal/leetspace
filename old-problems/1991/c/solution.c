int findMiddleIndex(int* nums, int numsSize) {
  int rightSum = 0;
  for (int i = 0; i < numsSize; ++i) rightSum += nums[i];

  int leftSum = 0;
  for (int i = 0; i < numsSize; ++i) {
    rightSum -= nums[i];
    if (leftSum == rightSum) return i;
    leftSum += nums[i];
  }

  return -1;
}
