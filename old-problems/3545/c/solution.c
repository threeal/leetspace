#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minDeletion(char* s, int k) {
  int freqs[26] = {0};
  for (char* c = s; *c != 0; ++c) ++freqs[*c - 'a'];

  qsort(freqs, 26, sizeof(int), compare);

  int deletion = 0;
  for (int i = k; i < 26; ++i) deletion += freqs[i];

  return deletion;
}
