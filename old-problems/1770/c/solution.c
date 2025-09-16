#include <stdlib.h>

int maximumScore(int* nums, int numsSize, int* multipliers, int multipliersSize) {
  int* memo = malloc((multipliersSize + 1) * sizeof(int));
  for (int i = 0; i <= multipliersSize; ++i) memo[i] = 0;

  for (int i = multipliersSize - 1; i >= 0; --i) {
    for (int l = 0, r = numsSize - i - 1; l <= i; ++l, ++r) {
      const int numL = nums[l] * multipliers[i] + memo[l + 1];
      const int numR = nums[r] * multipliers[i] + memo[l];
      memo[l] = numL >= numR ? numL : numR;
    }
  }

  return memo[0];
}
