int search(int* nums, int numsSize, int target) {
  if (target <= nums[numsSize - 1]) {
    if (target == nums[numsSize - 1]) return numsSize - 1;

    int low = 0, high = numsSize - 1;
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if (nums[mid] > nums[numsSize - 1] || nums[mid] < target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return nums[low] == target ? low : -1;
  } else if (target >= nums[0]) {
    if (target == nums[0]) return 0;

    int low = 0, high = numsSize - 1;
    while (low < high) {
      const int mid = high - (high - low) / 2;
      if (nums[mid] < nums[0] || nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }

    return nums[low] == target ? low : -1;
  } else {
    return -1;
  }
}
