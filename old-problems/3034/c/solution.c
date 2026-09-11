int countMatchingSubarrays(
    int* nums, int numsSize, int* pattern, int patternSize) {
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1]) {
      nums[i - 1] = 0;
    } else if (nums[i] > nums[i - 1]) {
      nums[i - 1] = 1;
    } else {
      nums[i - 1] = -1;
    }
  }

  int count = 0;
  for (int i = 0; i + patternSize < numsSize; ++i) {
    int j = 0;
    while (j < patternSize && nums[i + j] == pattern[j]) ++j;
    if (j == patternSize) ++count;
  }

  return count;
}
