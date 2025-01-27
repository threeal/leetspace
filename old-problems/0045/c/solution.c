int jump(int* nums, int numsSize) {
  int near = 0, far = 0, jumpCount = 0;
  while (far < numsSize - 1) {
    int farthest = 0;
    for (int i = near; i <= far; ++i) {
      farthest = farthest > i + nums[i] ? farthest : i + nums[i];
    }
    near = far + 1;
    far = farthest;
    ++jumpCount;
  }
  return jumpCount;
}
