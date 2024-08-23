#include <stdlib.h>

int nthUglyNumber(int n) {
  int* nums = malloc(n * sizeof(int));
  nums[0] = 1;

  int i2 = 0, i3 = 0, i5 = 0;
  for (int i = 1; i < n; ++i) {
    const int num2 = nums[i2] * 2;
    const int num3 = nums[i3] * 3;
    const int num5 = nums[i5] * 5;

    int min = num2 < num3 ? num2 : num3;
    if (num5 < min) min = num5;

    if (num2 == min) ++i2;
    if (num3 == min) ++i3;
    if (num5 == min) ++i5;

    nums[i] = min;
  }

  int res = nums[n - 1];
  free(nums);

  return res;
}
