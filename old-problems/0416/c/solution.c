#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canPartition(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) sum += nums[i];
  if (sum % 2 == 1) return false;
  sum /= 2;

  bool* prev = malloc((sum + 1) * sizeof(bool));
  memset(prev, 0, (sum + 1) * sizeof(bool));
  prev[0] = true;

  bool* curr = malloc((sum + 1) * sizeof(bool));
  memset(curr, 0, (sum + 1) * sizeof(bool));
  curr[0] = true;

  for (int i = 1; i < numsSize; ++i) {
    bool* temp = prev;
    prev = curr;
    curr = temp;

    for (int k = 1; k <= sum; ++k) {
      curr[k] = prev[k] || (nums[i] <= k ? prev[k - nums[i]] : false);
    }
  }

  const bool res = curr[sum];

  free(curr);
  free(prev);

  return res;
}
