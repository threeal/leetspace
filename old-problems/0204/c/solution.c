#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int countPrimes(int n) {
  if (n < 2) return 0;
  int count = 0;

  bool* nums = malloc(n * sizeof(bool));
  memset(nums, false, n * sizeof(bool));

  for (int i = 2; i < n; ++i) {
    if (!nums[i]) {
      ++count;
      for (int j = i + i; j < n; j += i) nums[j] = true;
    }
  }

  free(nums);
  return count;
}
