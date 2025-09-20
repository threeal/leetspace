int* smallestSubarrays(int* nums, int numsSize, int* returnSize) {
  int bitPos[32] = {0}, maxBits = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    while (nums[i] > (1 << maxBits)) ++maxBits;
    int maxPos = i;
    for (int j = 0; j <= maxBits; ++j) {
      if ((nums[i] & (1 << j)) != 0) {
        bitPos[j] = i;
      } else if (bitPos[j] > maxPos) {
        maxPos = bitPos[j];
      }
    }
    nums[i] = maxPos + 1 - i;
  }
  *returnSize = numsSize;
  return nums;
}
