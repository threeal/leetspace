long long zeroFilledSubarray(int* nums, int numsSize) {
  long long count = 0, zeros = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 0) {
      ++zeros;
    } else {
      count += ((zeros + 1) * zeros) / 2;
      zeros = 0;
    }
  }
  return count + ((zeros + 1) * zeros) / 2;
}
