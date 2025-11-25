int returnToBoundaryCount(int* nums, int numsSize) {
  int sum = 0, count = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    if (sum == 0) ++count;
  }
  return count;
}
