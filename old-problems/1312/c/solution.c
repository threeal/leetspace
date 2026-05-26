#include <stdlib.h>
#include <string.h>

int minInsertions(char* s) {
  const int sLen = strlen(s);
  int* dp = malloc((sLen + 1) * sizeof(int));
  memset(dp, 0, (sLen + 1) * sizeof(int));
  for (int i = 0; i < sLen; ++i) {
    int prev = dp[0];
    for (int j = 0; j < sLen; ++j) {
      const int temp = dp[j + 1];
      if (s[i] == s[sLen - j - 1]) {
        dp[j + 1] = prev + 1;
      } else {
        if (dp[j] > dp[j + 1]) dp[j + 1] = dp[j];
      }
      prev = temp;
    }
  }
  return sLen - dp[sLen];
}
