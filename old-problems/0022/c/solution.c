#include <stdlib.h>
#include <string.h>

const int outSize[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430};

void generate(char*** outIt, char* str, int i, int closers, int maxClosers);

char** generateParenthesis(int n, int* returnSize) {
  int strSize = (n * 2 + 1) * sizeof(char);
  char* str = malloc(strSize);
  str[0] = '(';
  str[n * 2 - 1] = ')';
  str[n * 2] = 0;

  char** out = malloc(outSize[n] * sizeof(char*));
  for (int i = outSize[n] - 1; i >= 0; --i) out[i] = malloc(strSize);

  char** outIt = out;
  generate(&outIt, str, (n * 2) - 2, 1, n);

  *returnSize = outSize[n];
  return out;
}

void generate(char*** outIt, char* str, int i, int closers, int maxClosers) {
  if (i == 0) {
    strcpy(**outIt, str);
    ++(*outIt);
  } else {
    if (closers < maxClosers) {
      str[i] = ')';
      generate(outIt, str, i - 1, closers + 1, maxClosers);
    }
    if (closers > 0) {
      str[i] = '(';
      generate(outIt, str, i - 1, closers - 1, maxClosers - 1);
    }
  }
}
