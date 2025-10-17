int evenNumberBitwiseORs(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] % 2 == 0) sum |= nums[i];
  }
  return sum;
}
