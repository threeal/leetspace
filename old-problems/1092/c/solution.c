#include <stdlib.h>
#include <string.h>

char* shortestCommonSupersequence(char* str1, char* str2) {
  const int str1Len = strlen(str1);
  const int str2Len = strlen(str2);

  const int lcsSize = str1Len + 1;
  int** lcs = malloc(lcsSize * sizeof(int*));

  const int lcsColSize = str2Len + 1;
  for (int i = 0; i < lcsSize; ++i) {
    lcs[i] = malloc(lcsColSize * sizeof(int));
    memset(lcs[i], 0, lcsColSize * sizeof(int));
  }

  for (int i = 1; i <= str1Len; ++i) {
    for (int j = 1; j <= str2Len; ++j) {
      if (str1[i - 1] == str2[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1] + 1;
      } else {
        lcs[i][j] = lcs[i - 1][j] >= lcs[i][j - 1]
            ? lcs[i - 1][j]
            : lcs[i][j - 1];
      }
    }
  }

  const int outputSize =
      str1Len + str2Len - lcs[lcsSize - 1][lcsColSize - 1] + 1;

  char* output = malloc(outputSize * sizeof(char));
  output[outputSize - 1] = '\0';

  int i = str1Len, j = str2Len, k = outputSize - 1;
  while (i > 0 && j > 0) {
    if (str1[i - 1] == str2[j - 1]) {
      output[--k] = str1[--i];
      --j;
    } else if (lcs[i - 1][j] >= lcs[i][j - 1]) {
      output[--k] = str1[--i];
    } else {
      output[--k] = str2[--j];
    }
  }

  while (i > 0) output[--k] = str1[--i];
  while (j > 0) output[--k] = str2[--j];

  for (int i = 0; i < lcsSize; ++i) free(lcs[i]);
  free(lcs);

  return output;
}
