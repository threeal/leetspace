#include <stdlib.h>
#include <string.h>

int* shortestToChar(char* s, char c, int* returnSize) {
  const int sLen = strlen(s);
  int* distances = malloc(sLen * sizeof(int));
  for (int i = 0; i < sLen; ++i) distances[i] = 0;

  int ci = sLen;
  for (int i = 0; i < sLen; ++i, ++ci) {
    if (s[i] == c) ci = 0;
    distances[i] = ci;
  }

  for (int i = sLen - 1; i >= 0; --i, ++ci) {
    if (s[i] == c) ci = 0;
    if (ci < distances[i]) distances[i] = ci;
  }

  *returnSize = sLen;
  return distances;
}
