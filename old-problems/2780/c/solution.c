int minimumIndex(int* nums, int numsSize) {
  int majority, count = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (count == 0) {
      majority = nums[i];
      ++count;
    } else if (nums[i] == majority) {
      ++count;
    } else {
      --count;
    }
  }

  int majorityCount = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == majority) ++majorityCount;
  }

  int leftCount = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == majority) {
      ++leftCount;
    }

    if (2 * leftCount > i + 1 &&
        2 * (majorityCount - leftCount) > numsSize - i - 1) {
      return i;
    }
  }

  return -1;
}
