#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
  qsort(g, gSize, sizeof(int), comp);
  qsort(s, sSize, sizeof(int), comp);

  int gi = 0;
  int si = 0;
  while (gi < gSize && si < sSize) {
    if (g[gi] <= s[si]) ++gi;
    ++si;
  }

  return gi;
}
