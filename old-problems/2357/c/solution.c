#include <stdbool.h>

int minimumOperations(int* nums, int numsSize) {
  bool exists[101] = {false};
  exists[0] = true;

  int uniques = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (!exists[nums[i]]) {
      exists[nums[i]] = true;
      ++uniques;
    }
  }

  return uniques;
}
