int minDeletion(int* nums, int numsSize) {
  int deletion = 0;
  for (int i = 1; i < numsSize; i += 2) {
    while (i < numsSize && nums[i - 1] == nums[i]) {
      ++deletion;
      ++i;
    }
  }
  if ((numsSize - deletion) % 2 != 0) ++deletion;
  return deletion;
}
