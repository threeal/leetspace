int maximumLength(int* nums, int numsSize) {
  int dp[2][2] = {{0, 0}, {0, 0}}, max = 0;
  for (int i = 0; i < numsSize; ++i) {
    nums[i] %= 2;

    dp[nums[i]][0] = dp[0][nums[i]] + 1;
    if (dp[nums[i]][0] > max) max = dp[nums[i]][0];

    dp[nums[i]][1] = dp[1][nums[i]] + 1;
    if (dp[nums[i]][1] > max) max = dp[nums[i]][1];
  }
  return max;
}
