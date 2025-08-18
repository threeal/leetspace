#include <stdlib.h>
#include <string.h>

char* generateTheString(int n) {
  char* s = malloc((n + 1) * sizeof(char));
  memset(s, 'a', n * sizeof(char));
  if (n % 2 == 0) s[0] = 'b';
  s[n] = 0;
  return s;
}
