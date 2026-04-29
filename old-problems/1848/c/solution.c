int getMinDistance(int* nums, int numsSize, int target, int start) {
  int minDist = numsSize;
  for (int i = 0; i < start; ++i) {
    if (nums[i] == target) {
      const int dist = start - i;
      if (dist < minDist) minDist = dist;
    }
  }
  for (int i = start; i < numsSize; ++i) {
    if (nums[i] == target) {
      const int dist = i - start;
      if (dist < minDist) minDist = dist;
    }
  }
  return minDist;
}
