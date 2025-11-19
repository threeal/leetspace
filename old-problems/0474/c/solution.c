#include <stdlib.h>
#include <string.h>

int findMaxForm(char** strs, int strsSize, int m, int n) {
  const int dpSize = m + 1;
  int** dp = malloc(dpSize * sizeof(int*));
  for (int i = 0; i < dpSize; ++i) {
    dp[i] = malloc((n + 1) * sizeof(int));
    memset(dp[i], 0, (n + 1) * sizeof(int));
  }

  for (int i = 0; i < strsSize; ++i) {
    int zeros = 0, ones = 0;
    for (char* c = strs[i]; *c != 0; ++c) {
      if (*c == '0') {
        ++zeros;
      } else {
        ++ones;
      }
    }

    for (int j = m; j >= zeros; --j) {
      for (int k = n; k >= ones; --k) {
        if (1 + dp[j - zeros][k - ones] > dp[j][k]) {
          dp[j][k] = 1 + dp[j - zeros][k - ones];
        }
      }
    }
  }

  const int res = dp[m][n];
  for (int i = 0; i < dpSize; ++i) free(dp[i]);
  free(dp);

  return res;
}
