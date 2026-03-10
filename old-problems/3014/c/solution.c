#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minimumPushes(char* word) {
  int freqs[26] = {0};
  for (char* c = word; *c != 0; ++c) ++freqs[*c - 'a'];

  qsort(freqs, 26, sizeof(int), compare);

  int sum = 0;
  for (int i = 0; i < 26 && freqs[i] != 0; ++i) {
    sum += (i / 8 + 1) * freqs[i];
  }

  return sum;
}
