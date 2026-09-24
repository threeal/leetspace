int minOperations(int* nums, int numsSize, int x) {
  int l = 0;
  while (l < numsSize && x > 0) x -= nums[l++];
  if (l == numsSize) return x == 0 ? numsSize : -1;

  int min = x == 0 ? l : numsSize + 1;
  int r = numsSize;
  while (l > 0) {
    x += nums[--l];
    while (x > 0) x -= nums[--r];
    if (x == 0 && l + numsSize - r < min) {
      min = l + numsSize - r;
    }
  }

  return min <= numsSize ? min : -1;
}
