int minZeroArray(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize) {
  return nums[numsSize - 1] *
      queries[queriesSize - 1][queriesColSize[queriesSize - 1] - 1];
}
