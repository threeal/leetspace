int maximumScore(int* nums, int numsSize, int k) {
  int left = k;
  int right = k;

  int minNum = nums[k];
  int maxScore = minNum;

  while (left > 0 || right < numsSize - 1) {
    if (left == 0 || (right < numsSize - 1 && nums[right + 1] > nums[left - 1])) {
      ++right;
      if (nums[right] < minNum) minNum = nums[right];
    } else {
      --left;
      if (nums[left] < minNum) minNum = nums[left];
    }
    const int newScore = minNum * (right - left + 1);
    if (newScore > maxScore) maxScore = newScore;
  }

  return maxScore;
}
