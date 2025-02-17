#include <string.h>

char* removeOccurrences(char* s, char* part) {
  const int sSize = strlen(s);
  const int partSize = strlen(part);
  if (sSize < partSize) return s;

  int n = partSize - 1;
  for (int i = n; i < sSize; ++i) {
    s[n] = s[i];
    ++n;
    if (n >= partSize && strncmp(s + n - partSize, part, partSize) == 0) {
      n -= partSize;
    }
  }

  s[n] = 0;
  return s;
}
