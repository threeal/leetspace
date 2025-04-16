#include <stdlib.h>

int* gFreqs;
int compare(const void* a, const void* b) {
  return gFreqs[*(char*)a] == gFreqs[*(char*)b]
      ? *(char*)a - *(char*)b
      : gFreqs[*(char*)b] - gFreqs[*(char*)a];
}

char* frequencySort(char* s) {
  int freqs[75] = {0};
  for (char* c = s; *c != 0; ++c) ++freqs[*c - '0'];

  char indices[75];
  for (char i = 0; i < 75; ++i) indices[i] = i;

  gFreqs = freqs;
  qsort(indices, 75, sizeof(char), compare);

  int i = 0;
  for (int j = 0; j < 75; ++j) {
    for (int n = freqs[indices[j]]; n > 0; --n) {
      s[i++] = '0' + indices[j];
    }
  }

  return s;
}
