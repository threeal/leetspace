#include <stdlib.h>
#include <string.h>

int subarraysDivByK(int* nums, int numsSize, int k) {
  int count = 0;

  int* counts = malloc(k * sizeof(int));
  memset(counts, 0, k * sizeof(int));
  counts[0] = 1;

  int sum = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    sum += nums[i];

    int mod = sum % k;
    if (mod < 0) mod += k;

    count += counts[mod];
    ++counts[mod];
  }

  free(counts);

  return count;
}
