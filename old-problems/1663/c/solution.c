#include <stdlib.h>
#include <string.h>

char* getSmallestString(int n, int k) {
  char* s = malloc((n + 1) * sizeof(char));
  s[n] = '\0';
  k -= n;
  memset(s, 'a', (n - k / 25) * sizeof(char));
  memset(s + n - k / 25, 'z', k / 25 * sizeof(char));
  if (k % 25 > 0) s[n - k / 25 - 1] += k % 25;
  return s;
}
