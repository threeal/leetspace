#include <stdlib.h>
#include <string.h>

static void explore(
    char*** out, int* maxOutSize, int* outSize, char* s, int sLen, int i);

char** letterCasePermutation(char* s, int* returnSize) {
  const int sLen = strlen(s);

  int maxOutSize = sLen;
  char** out = malloc(maxOutSize * sizeof(char*));
  int outSize = 0;

  explore(&out, &maxOutSize, &outSize, s, sLen, 0);

  *returnSize = outSize;
  return out;
}

static void explore(
    char*** out, int* maxOutSize, int* outSize, char* s, int sLen, int i) {
  if (s[i] == 0) {
    if (*outSize == *maxOutSize) {
      *maxOutSize *= 2;
      *out = realloc(*out, *maxOutSize * sizeof(char*));
    }
    (*out)[(*outSize)++] = s;
  } else {
    explore(out, maxOutSize, outSize, s, sLen, i + 1);
    if (s[i] > '9') {
      char* ss = malloc((sLen + 1) * sizeof(char));
      memcpy(ss, s, (sLen + 1) * sizeof(char));
      ss[i] += s[i] <= 'Z' ? 'a' - 'A' : 'A' - 'a';
      explore(out, maxOutSize, outSize, ss, sLen, i + 1);
    }
  }
}
