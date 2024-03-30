int numSubarrayProductLessThanK(int* nums, int numsSize, int k) {
  if (k <= 1) return 0;

  int count = 0;

  int left = 0;
  int right = 0;
  int product = 1;

  while (right < numsSize) {
    product *= nums[right];
    while (product >= k) {
      product /= nums[left];
      ++left;
    }
    count += right + 1 - left;
    ++right;
  }

  return count;
}
