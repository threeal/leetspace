#include <stdlib.h>

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int** dp = malloc(nums1Size * sizeof(int*));
  for (int i = 0; i < nums1Size; ++i) {
    dp[i] = malloc(nums2Size * sizeof(int));
  }

  dp[0][0] = nums1[0] * nums2[0];
  for (int j = 1; j < nums2Size; ++j) {
    dp[0][j] = nums1[0] * nums2[j] > dp[0][j - 1]
        ? nums1[0] * nums2[j]
        : dp[0][j - 1];
  }

  for (int i = 1; i < nums1Size; ++i) {
    dp[i][0] = nums1[i] * nums2[0] > dp[i - 1][0]
        ? nums1[i] * nums2[0]
        : dp[i - 1][0];

    for (int j = 1; j < nums2Size; ++j) {
      const int a = dp[i - 1][j - 1] > 0
          ? dp[i - 1][j - 1] + nums1[i] * nums2[j]
          : nums1[i] * nums2[j];

      const int b = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];

      dp[i][j] = a > b ? a : b;
    }
  }

  const int res = dp[nums1Size - 1][nums2Size - 1];

  for (int i = 0; i < nums1Size; ++i) free(dp[i]);
  free(dp);

  return res;
}
