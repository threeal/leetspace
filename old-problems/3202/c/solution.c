int maximumLength(int* nums, int numsSize, int k) {
  int max = 0;
  int dp[1000][1000] = {{0}};
  for (int i = 0; i < numsSize; ++i) {
    const int num = nums[i] % k;
    for (int prev = 0; prev < k; ++prev) {
      dp[num][prev] = dp[prev][num] + 1;
      if (dp[num][prev] > max) max = dp[num][prev];
    }
  }
  return max;
}
