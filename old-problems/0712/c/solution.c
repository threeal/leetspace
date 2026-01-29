#include <stdlib.h>
#include <string.h>

int minimumDeleteSum(char* s1, char* s2) {
  const int s1len = strlen(s1);
  const int s2len = strlen(s2);

  int* dp = malloc((s2len + 1) * sizeof(int));
  memset(dp, 0, (s2len + 1) * sizeof(int));

  for (int i = 0; i < s1len; ++i) {
    int prevTl = 0;
    for (int j = 0; j < s2len; ++j) {
      if (s1[i] == s2[j]) {
        const int tempPrevTl = prevTl;
        prevTl = dp[j + 1];
        dp[j + 1] = tempPrevTl + s1[i];
      } else {
        prevTl = dp[j + 1];
        if (dp[j] > dp[j + 1]) dp[j + 1] = dp[j];
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < s1len; ++i) sum += s1[i];
  for (int i = 0; i < s2len; ++i) sum += s2[i];

  return sum - 2 * dp[s2len];
}
