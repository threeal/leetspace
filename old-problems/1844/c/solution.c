#include <string.h>

char* replaceDigits(char* s) {
  const int sLen = strlen(s);
  for (int i = 1; i < sLen; i += 2) {
    s[i] += s[i - 1] - '0';
  }
  return s;
}
