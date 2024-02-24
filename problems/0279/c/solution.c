#include <stdlib.h>

int numSquares(int n) {
  int* dp = malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n + 1; ++i) {
    dp[i] = 10000;
  }

  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      const int val = dp[i - j * j] + 1;
      if (val < dp[i]) dp[i] = val;
    }
  }

  return dp[n];
}
