int maxRotateFunction(int* nums, int numsSize) {
  int value = 0, sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    value += nums[i] * i;
    sum += nums[i];
  }

  int maxValue = value;
  for (int i = 0; i < numsSize; ++i) {
    value += nums[i] * numsSize - sum;
    if (value > maxValue) maxValue = value;
  }

  return maxValue;
}
