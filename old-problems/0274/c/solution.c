#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int hIndex(int* citations, int citationsSize) {
  qsort(citations, citationsSize, sizeof(int), compare);
  for (int n = citationsSize; n > 0; --n) {
    if (citations[citationsSize - n] >= n) return n;
  }
  return 0;
}
