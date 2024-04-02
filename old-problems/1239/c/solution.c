#include <stdint.h>
#include <stdlib.h>

int fn(uint32_t* uniques, int uniquesSize, int i, uint32_t unique);

int maxLength(char** arr, int arrSize) {
  uint32_t* uniques = malloc(sizeof(uint32_t) * arrSize);
  for (int i = 0; i < arrSize; ++i) {
    uniques[i] = 0;
    char* c = arr[i];
    while (*c != 0) {
      uint32_t div = 1 << (*c - 'a');
      if ((uniques[i] & div) != 0) {
        uniques[i] = 0;
        break;
      }
      uniques[i] |= div;
      ++c;
    }
  }

  const int len = fn(uniques, arrSize, 0, 0);

  free(uniques);
  return len;
}

int fn(uint32_t* uniques, int uniquesSize, int i, uint32_t unique) {
  if (i == uniquesSize) {
    return __builtin_popcount(unique);
  }

  if ((unique & uniques[i]) == 0) {
    int pick = fn(uniques, uniquesSize, i + 1, unique | uniques[i]);
    int notPick = fn(uniques, uniquesSize, i + 1, unique);
    return pick > notPick ? pick : notPick;
  } else {
    return fn(uniques, uniquesSize, i + 1, unique);
  }
}
