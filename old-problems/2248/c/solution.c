int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
  *returnSize = numsColSize[numsSize - 1];
  return nums[numsSize - 1];
}
