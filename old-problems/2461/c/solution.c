long long maximumSubarraySum(int* nums, int numsSize, int k) {
  long long maxSum = 0, sum = 0;
  int freqs[100001] = {0}, freqsSize = 0;

  for (int i = 0; i < k; ++i) {
    sum += nums[i];
    if (++freqs[nums[i]] == 1) ++freqsSize;
  }

  if (freqsSize == k) maxSum = sum;

  for (int i = k; i < numsSize; ++i) {
    sum += nums[i] - nums[i - k];

    if (nums[i] != nums[i - k]) {
      if (--freqs[nums[i - k]] == 0) --freqsSize;
      if (++freqs[nums[i]] == 1) ++freqsSize;
    }

    if (freqsSize == k && sum > maxSum) maxSum = sum;
  }

  return maxSum;
}
