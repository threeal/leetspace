int maxAbsoluteSum(int* nums, int numsSize) {
  int negativeSum = 0, positiveSum = 0, minNegative = 0, maxPositive = 0;
  for (int i = 0; i < numsSize; ++i) {
    negativeSum += nums[i];
    if (negativeSum > 0) {
      negativeSum = 0;
    } else if (negativeSum < minNegative) {
      minNegative = negativeSum;
    }

    positiveSum += nums[i];
    if (positiveSum < 0) {
      positiveSum = 0;
    } else if (positiveSum > maxPositive) {
      maxPositive = positiveSum;
    }
  }

  return -minNegative > maxPositive ? -minNegative : maxPositive;
}
