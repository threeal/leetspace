int minimumDistance(int* nums, int numsSize) {
  int minDist = numsSize * 3;
  for (int i = 0; i < numsSize; ++i) {
    for (int j = i + 1; j < numsSize; ++j) {
      if (nums[i] == nums[j]) {
        for (int k = j + 1; k < numsSize; ++k) {
          if (nums[j] == nums[k]) {
            const int dist = 2 * (k - i);
            if (dist < minDist) minDist = dist;
          }
        }
      }
    }
  }
  return minDist == numsSize * 3 ? -1 : minDist;
}
