#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool isGood(int* nums, int numsSize) {
  const int n = numsSize - 1;

  const int existsSize = n / 8 + 1;
  uint8_t* exists = malloc(existsSize * sizeof(uint8_t));
  memset(exists, 0, existsSize * sizeof(uint8_t));

  int nCount = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > n) {
      free(exists);
      return false;
    }

    if (nums[i] < n) {
      if ((exists[nums[i] / 8] & (1 << (nums[i] % 8))) != 0) {
        free(exists);
        return false;
      }
      exists[nums[i] / 8] |= 1 << (nums[i] % 8);
    } else {
      if (++nCount == 3) {
        free(exists);
        return false;
      }
    }
  }

  free(exists);
  return true;
}
