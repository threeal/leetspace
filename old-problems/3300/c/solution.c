int minElement(int* nums, int numsSize) {
  int minSum = nums[0];
  for (int i = 0; i < numsSize; ++i) {
    int sum = 0;
    while (nums[i] > 0) {
      sum += nums[i] % 10;
      nums[i] /= 10;
    }
    if (sum < minSum) minSum = sum;
  }
  return minSum;
}
