int singleNumber(int* nums, int numsSize) {
  int onces = 0;
  int twices = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    onces ^= nums[i] & ~twices;
    twices ^= nums[i] & ~onces;
  }
  return onces;
}
