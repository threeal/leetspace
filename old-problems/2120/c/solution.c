#include <stdlib.h>
#include <string.h>

int* executeInstructions(
    int n, int* startPos, int startPosSize, char* s, int* returnSize) {
  (void)startPosSize;
  const int sLen = strlen(s);
  int* output = malloc(sLen * sizeof(int));
  for (int i = 0; i < sLen; ++i) {
    int y = startPos[0], x = startPos[1], j = i;
    while (j < sLen) {
      if (s[j] == 'L') {
        if (--x < 0) break;
      } else if (s[j] == 'R') {
        if (++x >= n) break;
      } else if (s[j] == 'U') {
        if (--y < 0) break;
      } else {
        if (++y >= n) break;
      }
      ++j;
    }
    output[i] = j - i;
  }
  *returnSize = sLen;
  return output;
}
