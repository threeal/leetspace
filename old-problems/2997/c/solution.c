int minOperations(int* nums, int numsSize, int k) {
  while (--numsSize >= 0) {
    k ^= *nums;
    ++nums;
  }
  return __builtin_popcount(k);
}
