#include <stdlib.h>

long long* findPrefixScore(int* nums, int numsSize, int* returnSize) {
  long long* score = malloc(numsSize * sizeof(long long));

  long long sum = 0;
  for (int maxNum = 0, i = 0; i < numsSize; ++i) {
    if (nums[i] >= maxNum) maxNum = nums[i];
    sum += nums[i] + maxNum;
    score[i] = sum;
  }

  *returnSize = numsSize;
  return score;
}
