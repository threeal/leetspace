#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
  const int s1Len = strlen(s1);
  const int s2Len = strlen(s2);
  const int s3Len = strlen(s3);

  if (s1Len + s2Len != s3Len) return false;

  bool dp[101] = {false};
  dp[0] = true;

  for (int i = 1; i <= s2Len; ++i) {
    dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];
  }

  for (int i = 1; i <= s1Len; ++i) {
    dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
    for (int j = 1; j <= s2Len; ++j) {
      dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
          (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
    }
  }

  return dp[s2Len];
}
