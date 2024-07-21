int singleNumber(int* nums, int numsSize) {
  int sum = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    sum ^= nums[i];
  }
  return sum;
}
