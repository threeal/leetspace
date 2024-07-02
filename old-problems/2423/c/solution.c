#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(uint8_t*)a - *(uint8_t*)b;
}

bool equalFrequency(char* word) {
  uint8_t frequencies[26] = {0};

  while (*word != 0) {
    ++frequencies[*word - 'a'];
    ++word;
  }

  qsort(frequencies, 26, sizeof(uint8_t), comp);
  for (int i = 0; i < 25; ++i) {
    switch (frequencies[i]) {
      case 0:
        continue;

      case 1:
        if (frequencies[25] == 1) return true;
        if (frequencies[i + 1] == frequencies[25]) return true;
    }

    return frequencies[i] == frequencies[24] &&
        frequencies[i] + 1 == frequencies[25];
  }

  return true;
}
