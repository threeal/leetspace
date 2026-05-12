#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(uint32_t*)a - *(uint32_t*)b;
}

int similarPairs(char** words, int wordsSize) {
  uint32_t* masks = malloc(wordsSize * sizeof(uint32_t));
  for (int i = 0; i < wordsSize; ++i) {
    uint32_t mask = 0;
    for (char* c = words[i]; *c != 0; ++c) {
      mask |= 1 << (*c - 'a');
    }
    masks[i] = mask;
  }

  qsort(masks, wordsSize, sizeof(uint32_t), compare);

  int l = 0, pairs = 0;
  for (int r = 1; r < wordsSize; ++r) {
    if (masks[l] != masks[r]) {
      pairs += (r - l) * (r - l - 1) / 2;
      l = r;
    }
  }

  return pairs + (wordsSize - l) * (wordsSize - l - 1) / 2;
}
