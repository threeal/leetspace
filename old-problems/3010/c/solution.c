int minimumCost(int* nums, int numsSize) {
  int a = nums[1] < nums[2] ? nums[1] : nums[2];
  int b = nums[1] < nums[2] ? nums[2] : nums[1];
  for (int i = 3; i < numsSize; ++i) {
    if (nums[i] < a) {
      b = a;
      a = nums[i];
    } else if (nums[i] < b) {
      b = nums[i];
    }
  }
  return nums[0] + a + b;
}
