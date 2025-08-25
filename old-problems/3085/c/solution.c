#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minimumDeletions(char* word, int k) {
  int freqs[26] = {0};

  int wordLen = 0;
  while (word[wordLen] != 0) {
    ++freqs[word[wordLen] - 'a'];
    ++wordLen;
  }

  qsort(freqs, 26, sizeof(int), compare);

  int l = 0, sum = 0, maxInclude = 0;
  for (int r = 0; r < 26 && freqs[r] != 0; ++r) {
    sum += freqs[r];
    while (freqs[l] > freqs[r] + k) {
      sum -= freqs[l];
      ++l;
    }
    const int include = sum + l * (freqs[r] + k);
    if (include > maxInclude) maxInclude = include;
  }

  return wordLen - maxInclude;
}
