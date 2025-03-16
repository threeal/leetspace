int minCapability(int* nums, int numsSize, int k) {
  int low = 0, high = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > high) high = nums[i];
  }

  while (low < high) {
    const int mid = low + (high - low) / 2;

    int count = 0;
    for (int i = 0; i < numsSize; ++i) {
      if (nums[i] <= mid) {
        if (++count == k) break;
        ++i;
      }
    }

    if (count != k) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}
