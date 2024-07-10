#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int minKBitFlips(int* nums, int numsSize, int k) {
  int mustFlipsSize = numsSize / 8 + (numsSize % 8 == 0 ? 0 : 1);
  uint8_t* mustFlips = malloc(mustFlipsSize);
  memset(mustFlips, 0, mustFlipsSize);

  int target = 1;
  int flip = 0;
  for (int i = numsSize - 1; i >= k; --i) {
    if (mustFlips[i / 8] >> i % 8 & 1) target = target == 0 ? 1 : 0;
    if (nums[i] != target) {
      mustFlips[(i - k) / 8] |= 1 << (i - k) % 8;
      target = target == 0 ? 1 : 0;
      ++flip;
    }
  }

  if (mustFlips[(k - 1) / 8] >> (k - 1) % 8 & 1) target = target == 0 ? 1 : 0;
  if (nums[k - 1] == target) {
    for (int i = k - 2; i >= 0; --i) {
      if (mustFlips[i / 8] >> i % 8 & 1) target = target == 0 ? 1 : 0;
      if (nums[i] != target) {
        free(mustFlips);
        return -1;
      }
    }
    free(mustFlips);
    return flip;
  } else {
    for (int i = k - 2; i >= 0; --i) {
      if (mustFlips[i / 8] >> i % 8 & 1) target = target == 0 ? 1 : 0;
      if (nums[i] == target) {
        free(mustFlips);
        return -1;
      }
    }
    free(mustFlips);
    return flip + 1;
  }
}
