#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minimumPushes(char* word) {
  int freqs[26] = {0};
  while (*word != 0) {
    ++freqs[*word - 'a'];
    ++word;
  }

  qsort(freqs, 26, sizeof(int), compare);

  int pushes = 0;
  for (int i = 0; i < 26 && freqs[i] > 0; ++i) {
    pushes += freqs[i] * (i / 8 + 1);
  }
  return pushes;
}
