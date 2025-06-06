#include <stdlib.h>
#include <string.h>

char* mergeAlternately(char* word1, char* word2) {
  const int word1Len = strlen(word1);
  const int word2Len = strlen(word2);

  char* output = malloc((word1Len + word2Len + 1) * sizeof(char));
  int outputSize = 0;

  int n = word1Len <= word2Len ? word1Len : word2Len;
  for (int i = 0; i < n; ++i) {
    output[outputSize++] = word1[i];
    output[outputSize++] = word2[i];
  }

  for (int i = n; i < word1Len; ++i) output[outputSize++] = word1[i];
  for (int i = n; i < word2Len; ++i) output[outputSize++] = word2[i];

  output[outputSize] = 0;
  return output;
}
