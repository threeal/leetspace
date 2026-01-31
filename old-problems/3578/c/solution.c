#include <stdlib.h>

int countPartitions(int* nums, int numsSize, int k) {
  long long sum = 0;
  long long* sums = malloc((numsSize + 1) * sizeof(long long));
  sums[0] = 1;

  int* mins = malloc(numsSize * sizeof(int));
  int minsL = 0, minsR = 0;

  int* maxs = malloc(numsSize * sizeof(int));
  int maxsL = 0, maxsR = 0;

  for (int l = 0, r = 0; r < numsSize; ++r) {
    while (minsL < minsR && nums[mins[minsR - 1]] >= nums[r]) --minsR;
    mins[minsR++] = r;

    while (maxsL < maxsR && nums[maxs[maxsR - 1]] <= nums[r]) --maxsR;
    maxs[maxsR++] = r;

    sum = (sum + sums[r]) % 1000000007;

    while (nums[maxs[maxsL]] - nums[mins[minsL]] > k) {
      if (mins[minsL] < maxs[maxsL]) {
        const int ll = mins[minsL] + 1;
        ++minsL;

        for (int i = l; i < ll; ++i) {
          sum = (1000000007 + sum - sums[i]) % 1000000007;
        }
        l = ll;
      } else {
        const int ll = maxs[maxsL] + 1;
        ++maxsL;

        for (int i = l; i < ll; ++i) {
          sum = (1000000007 + sum - sums[i]) % 1000000007;
        }
        l = ll;
      }
    }

    sums[r + 1] = sum;
  }

  free(sums);
  free(mins);
  free(maxs);

  return sum;
}
