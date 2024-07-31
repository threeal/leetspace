#include <stdlib.h>
#include <string.h>

char* removeDuplicates(char* s, int k) {
  int n = strlen(s);
  int* freqs = malloc(n * sizeof(int));

  int out = 0;
  for (int i = 0; i < n; ++i) {
    while (
        out > 0 && i < n &&
        s[out - 1] == s[i] && freqs[out - 1] + 1 >= k) {
      --out;
      ++i;
    }
    if (i < n) {
      if (out > 0 && s[out - 1] == s[i]) {
        ++freqs[out - 1];
      } else {
        s[out] = s[i];
        freqs[out] = 1;
        ++out;
      }
    }
  }

  int pos = 0;
  for (int i = out - 1; i >= 0; --i) {
    pos += freqs[i];
  }

  s[pos] = 0;
  for (int i = out - 1; i >= 0; --i) {
    pos -= freqs[i];
    memset(s + pos, s[i], freqs[i] * sizeof(char));
  }

  free(freqs);

  return s;
}
