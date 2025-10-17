#include <limits.h>
#include <stdlib.h>

int minScoreTriangulation(int* values, int valuesSize) {
  const int dpSize = valuesSize - 2;
  int** dp = malloc(dpSize * sizeof(int*));

  for (int i = 0; i < dpSize; ++i) {
    const int dpISize = valuesSize - i - 2;
    dp[i] = malloc(dpISize * sizeof(int));

    for (int j = 0; j < dpISize; ++j) {
      int minScore = INT_MAX;
      for (int k = 0; k <= i; ++k) {
        int score = values[j] * values[j + k + 1] * values[j + i + 2];
        if (k > 0) score += dp[k - 1][j];
        if (k < i) score += dp[i - k - 1][j + k + 1];
        if (score < minScore) minScore = score;
      }
      dp[i][j] = minScore;
    }
  }

  const int res = dp[dpSize - 1][valuesSize - dpSize - 2];

  for (int i = 0; i < dpSize; ++i) free(dp[i]);
  free(dp);

  return res;
}
