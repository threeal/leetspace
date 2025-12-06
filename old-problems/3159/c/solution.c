int* occurrencesOfElement(
    int* nums, int numsSize, int* queries, int queriesSize, int x,
    int* returnSize) {
  int n = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == x) nums[n++] = i;
  }

  for (int i = 0; i < queriesSize; ++i) {
    queries[i] = queries[i] <= n ? nums[queries[i] - 1] : -1;
  }

  *returnSize = queriesSize;
  return queries;
}
