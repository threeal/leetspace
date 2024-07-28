int countQuadruplets(int* nums, int numsSize) {
  int count = 0;
  for (int d = numsSize - 1; d >= 3; --d) {
    for (int c = d - 1; c >= 2; --c) {
      for (int b = c - 1; b >= 1; --b) {
        for (int a = b - 1; a >= 0; --a) {
          if (nums[a] + nums[b] + nums[c] == nums[d]) ++count;
        }
      }
    }
  }
  return count;
}
