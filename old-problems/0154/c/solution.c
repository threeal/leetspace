int findMin(int* nums, int numsSize) {
  if (nums[0] < nums[numsSize - 1]) return nums[0];

  int low = 0, high = numsSize - 1;
  while (low < high) {
    const int mid = low + (high - low) / 2;
    if (nums[mid] < nums[high]) {
      high = mid;
    } else if (nums[mid] > nums[high]) {
      low = mid + 1;
    } else {
      --high;
    }
  }

  return nums[low];
}
