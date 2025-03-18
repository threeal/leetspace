int maximumCount(int* nums, int numsSize) {
  int plow = numsSize;
  if (nums[numsSize - 1] > 0) {
    plow = 0;
    int high = numsSize - 1;
    while (plow < high) {
      const int mid = plow + (high - plow) / 2;
      if (nums[mid] <= 0) {
        plow = mid + 1;
      } else {
        high = mid;
      }
    }
  }

  int nlow = -1;
  if (nums[0] < 0) {
    nlow = 0;
    int high = numsSize - 1;
    while (nlow < high) {
      const int mid = high - (high - nlow) / 2;
      if (nums[mid] >= 0) {
        high = mid - 1;
      } else {
        nlow = mid;
      }
    }
  }

  return numsSize - plow >= nlow + 1 ? numsSize - plow : nlow + 1;
}
