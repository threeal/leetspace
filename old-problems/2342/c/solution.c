int maximumSum(int* nums, int numsSize) {
  int max = -1;
  int maxOfSum[82] = {0};
  for (int i = 0; i < numsSize; ++i) {
    int sum = 0;
    for (int n = nums[i]; n > 0; n /= 10) sum += n % 10;
    if (maxOfSum[sum] > 0 && maxOfSum[sum] + nums[i] > max) {
      max = maxOfSum[sum] + nums[i];
    }
    if (nums[i] > maxOfSum[sum]) maxOfSum[sum] = nums[i];
  }
  return max;
}
