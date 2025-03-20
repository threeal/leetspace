#include <stdbool.h>

bool divideArray(int* nums, int numsSize) {
  int freqs[501] = {0};

  int odds = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (++freqs[nums[i]] % 2 == 0) {
      --odds;
    } else {
      ++odds;
    }
  }

  return odds == 0;
}
