int minMoves(int* nums, int numsSize) {
  int moves = 0, max = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > max) {
      moves += (nums[i] - max) * i;
      max = nums[i];
    } else {
      moves += max - nums[i];
    }
  }
  return moves;
}
