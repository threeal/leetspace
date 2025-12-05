int unequalTriplets(int* nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] == nums[j]) continue;
      for (int k = j + 1; k < numsSize; ++k) {
        if (nums[i] != nums[k] && nums[j] != nums[k]) ++count;
      }
    }
  }
  return count;
}
