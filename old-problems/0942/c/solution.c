#include <stdlib.h>
#include <string.h>

int* diStringMatch(char* s, int* returnSize) {
  const int sLen = strlen(s);
  int* output = malloc((sLen + 1) * sizeof(int));
  int a = 0, b = sLen;
  for (int i = 0; i < sLen; ++i) {
    output[i] = s[i] == 'I' ? a++ : b--;
  }
  output[sLen] = a;
  *returnSize = sLen + 1;
  return output;
}
