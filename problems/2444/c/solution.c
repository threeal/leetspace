long long countSubarrays(int* nums, int numsSize, int minK, int maxK) {
  long long count = 0;

  int left = 0;
  int right = 0;

  int minPos = -1;
  int maxPos = -1;

  while (right < numsSize) {
    if (nums[right] < minK || nums[right] > maxK) {
      left = right + 1;
    } else {
      if (nums[right] == minK) minPos = right;
      if (nums[right] == maxK) maxPos = right;
      const int pos = minPos < maxPos ? minPos : maxPos;
      if (pos >= left) count += pos - left + 1;
    }
    ++right;
  }

  return count;
}
