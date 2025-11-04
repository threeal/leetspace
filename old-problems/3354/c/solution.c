int countValidSelections(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
  }

  int count = 0, prefix = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 0) {
      if (prefix * 2 == sum) count += 2;
      if (prefix * 2 + 1 == sum || prefix * 2 - 1 == sum) ++count;
    }
    prefix += nums[i];
  }

  return count;
}
