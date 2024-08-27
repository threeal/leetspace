#include <stdlib.h>
#include <string.h>

int strangePrinterRange(int** caches, const char* s, int l, int r);

int strangePrinter(char* s) {
  int n = 0, i = 0;
  while (s[i] != 0) {
    s[n] = s[i];
    ++i;
    while (s[i] != 0 && s[i] == s[n]) ++i;
    ++n;
  }

  int** caches = malloc(n * sizeof(int*));
  for (int i = 0; i < n; ++i) {
    caches[i] = malloc((n - i) * sizeof(int));
    memset(caches[i], -1, (n - i) * sizeof(int));
  }

  const int res = strangePrinterRange(caches, s, 0, n - 1);

  for (int i = 0; i < n; ++i) free(caches[i]);
  free(caches);

  return res;
}

int strangePrinterRange(int** caches, const char* s, int l, int r) {
  if (r - l < 0) return 0;

  int* cache = caches[l] + r - l;
  if (*cache < 0) {
    *cache = 1 + strangePrinterRange(caches, s, l + 1, r);
    for (int i = l + 1; i <= r; ++i) {
      if (s[i] == s[l]) {
        const int res = strangePrinterRange(caches, s, l, i - 1) +
            strangePrinterRange(caches, s, i + 1, r);
        if (res < *cache) *cache = res;
      }
    }
  }

  return *cache;
}
