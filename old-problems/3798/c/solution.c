#include <string.h>

char* largestEven(char* s) {
  int n = strlen(s);
  while (n != 0 && s[n - 1] == '1') --n;
  s[n] = 0;
  return s;
}
