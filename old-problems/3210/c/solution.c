#include <stdlib.h>
#include <string.h>

char* getEncryptedString(char* s, int k) {
  const int sLen = strlen(s);
  char* out = malloc((sLen + 1) * sizeof(char));
  memset(out, ' ', (sLen + 1) * sizeof(char));
  for (int i = 0; i < sLen; ++i) {
    out[i] = s[(i + k) % sLen];
  }
  out[sLen] = 0;
  return out;
}
