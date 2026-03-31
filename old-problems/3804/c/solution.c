int centeredSubarrays(int* nums, int numsSize) {
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    int sum = 0;
    for (int j = i; j < numsSize; ++j) {
      sum += nums[j];
      for (int k = i; k <= j; ++k) {
        if (sum == nums[k]) {
          ++count;
          break;
        }
      }
    }
  }
  return count;
}
