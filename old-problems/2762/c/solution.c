#include <stdlib.h>

long long continuousSubarrays(int* nums, int numsSize) {
  long long count = 0;

  int* mins = malloc(numsSize * sizeof(int));
  int mins_front = 0, mins_back = 0;

  int* maxs = malloc(numsSize * sizeof(int));
  int maxs_front = 0, maxs_back = 0;

  for (int l = 0, r = 0; r < numsSize; ++r) {
    while (mins_front < mins_back && nums[r] < mins[mins_back - 1]) --mins_back;
    mins[mins_back++] = nums[r];

    while (maxs_front < maxs_back && nums[r] > maxs[maxs_back - 1]) --maxs_back;
    maxs[maxs_back++] = nums[r];

    while (maxs[maxs_front] - mins[mins_front] > 2) {
      if (mins_front < mins_back && nums[l] == mins[mins_front]) ++mins_front;
      if (maxs_front < maxs_back && nums[l] == maxs[maxs_front]) ++maxs_front;
      ++l;
    }

    count += r + 1 - l;
  }

  return count;
}
