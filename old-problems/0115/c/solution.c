#include <stdlib.h>
#include <string.h>

int numDistinct(char* s, char* t) {
  int sLen = strlen(s);
  int tLen = strlen(t);
  if (tLen > sLen) return 0;

  int l = 0, r = sLen - tLen + 1;

  const int countsSize = r;
  long long* counts = malloc(countsSize * sizeof(long long));

  for (int i = 0; i < r; ++i) counts[i] = 1;
  for (int k = 0; k < tLen; ++k, ++l, ++r) {
    while (l < r && s[l] != t[k]) ++l;
    if (l == r) return 0;

    long long count = 0;
    for (int i = l; i < r; ++i) {
      if (s[i] == t[k]) count += counts[i - k];
      counts[i - k] = count;
    }
  }

  return counts[countsSize - 1];
}
