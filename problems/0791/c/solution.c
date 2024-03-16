#include <stdlib.h>
#include <string.h>

int orderOf[26];

int comp(const void* a, const void* b) {
  return orderOf[*(char*)a - 'a'] - orderOf[*(char*)b - 'a'];
}

char* customSortString(char* order, char* s) {
  for (int i = 0; order[i] != 0; ++i) {
    orderOf[order[i] - 'a'] = i;
  }

  qsort(s, strlen(s), sizeof(char), comp);

  return s;
}
