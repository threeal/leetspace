int xorAfterQueries(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize) {
  (void)queriesColSize;

  for (int i = 0; i < queriesSize; ++i) {
    for (int j = queries[i][0]; j <= queries[i][1]; j += queries[i][2]) {
      nums[j] = ((long long)nums[j] * queries[i][3]) % 1000000007;
    }
  }

  int ans = 0;
  for (int i = 0; i < numsSize; ++i) ans ^= nums[i];
  return ans;
}
