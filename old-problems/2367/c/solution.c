int arithmeticTriplets(int* nums, int numsSize, int diff) {
  int count = 0;
  for (int i = 0, j = 1, k = 2; k < numsSize; ++k) {
    while (j < k && nums[j] + diff < nums[k]) ++j;
    while (i < j && nums[i] + diff < nums[j]) ++i;
    if (nums[i] + diff == nums[j] && nums[j] + diff == nums[k]) ++count;
  }
  return count;
}
