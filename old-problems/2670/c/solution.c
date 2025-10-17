int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize) {
  int sFreqs[51] = {0}, sCount = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (++sFreqs[nums[i]] == 1) ++sCount;
  }

  int pFreqs[51] = {0}, pCount = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (++pFreqs[nums[i]] == 1) ++pCount;
    if (--sFreqs[nums[i]] == 0) --sCount;
    nums[i] = pCount - sCount;
  }

  *returnSize = numsSize;
  return nums;
}
