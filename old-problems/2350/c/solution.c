#include <stdlib.h>
#include <string.h>

int shortestSequence(int* rolls, int rollsSize, int k) {
  const int existsSize = (k + 1) / 8 + 1;
  char* exists = malloc(existsSize * sizeof(char));
  memset(exists, 0, existsSize * sizeof(char));

  int existCount = 0;
  int shortest = 1;
  for (int i = 0; i < rollsSize; ++i) {
    if ((exists[rolls[i] / 8] & (1 << (rolls[i] % 8))) == 0) {
      if (++existCount == k) {
        ++shortest;
        memset(exists, 0, existsSize * sizeof(char));
        existCount = 0;
      } else {
        exists[rolls[i] / 8] |= 1 << (rolls[i] % 8);
      }
    }
  }

  return shortest;
}
