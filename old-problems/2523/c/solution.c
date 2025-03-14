#include <stdbool.h>
#include <string.h>

int* closestPrimes(int left, int right, int* returnSize) {
  static bool flags[1000001];
  memset(flags, false, (right + 1) * sizeof(bool));

  for (int i = 2; i < left; ++i) {
    if (!flags[i]) {
      for (int j = i + i; j <= right; j += i) flags[j] = true;
    }
  }

  int a = -right, b = right, prev = -right;
  for (int i = left > 2 ? left : 2; i <= right; ++i) {
    if (!flags[i]) {
      if (i - prev < b - a) a = prev, b = i;
      for (int j = i + i; j <= right; j += i) flags[j] = true;
      prev = i;
    }
  }

  static int output[2];

  output[0] = a >= 0 ? a : -1;
  output[1] = a >= 0 ? b : -1;

  *returnSize = 2;
  return output;
}
