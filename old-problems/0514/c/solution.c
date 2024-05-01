#include <limits.h>
#include <stdlib.h>
#include <string.h>

int findRotateStepsRecursively(char* ring, int ringSize, char* key, int keySize, int** positions, int* positionsSizes, int** cache, int ringPos, int keyPos);

int findRotateSteps(char* ring, char* key) {
  int ringSize = strlen(ring);
  int keySize = strlen(key);

  int positionsSizes[26] = {0};
  for (int i = 0; i < ringSize; ++i) {
    ring[i] -= 'a';
    ++positionsSizes[ring[i]];
  }

  for (int i = 0; i < keySize; ++i) key[i] -= 'a';

  int* positions[26];
  for (int i = 0; i < 26; ++i) positions[i] = malloc(positionsSizes[i] * sizeof(int));
  memset(positionsSizes, 0, 26 * sizeof(int));
  for (int i = 0; i < ringSize; ++i) positions[ring[i]][positionsSizes[ring[i]]++] = i;

  int** cache = malloc(ringSize * sizeof(int*));
  cache[0] = malloc(keySize * sizeof(int));
  for (int i = 0; i < keySize; ++i) cache[0][i] = -1;
  for (int i = 1; i < ringSize; ++i) {
    cache[i] = malloc(keySize * sizeof(int));
    memcpy(cache[i], cache[0], keySize * sizeof(int));
  }

  int res = findRotateStepsRecursively(ring, ringSize, key, keySize, positions, positionsSizes, cache, 0, 0);

  for (int i = 0; i < ringSize; ++i) free(cache[i]);
  free(cache);

  for (int i = 0; i < 26; ++i) free(positions[i]);

  return res;
}

int findRotateStepsRecursively(char* ring, int ringSize, char* key, int keySize, int** positions, int* positionsSizes, int** cache, int ringPos, int keyPos) {
  if (keyPos == keySize) return 0;

  if (cache[ringPos][keyPos] < 0) {
    int minStep = INT_MAX;
    for (int i = 0; i < positionsSizes[key[keyPos]]; ++i) {
      const int pos = positions[key[keyPos]][i];
      const int distance = pos > ringPos
          ? pos - ringPos < ringSize + ringPos - pos ? pos - ringPos : ringSize + ringPos - pos
          : ringPos - pos < ringSize + pos - ringPos ? ringPos - pos
                                                     : ringSize + pos - ringPos;
      const int step = 1 + distance + findRotateStepsRecursively(ring, ringSize, key, keySize, positions, positionsSizes, cache, pos, keyPos + 1);
      if (step < minStep) minStep = step;
    }
    cache[ringPos][keyPos] = minStep;
  }

  return cache[ringPos][keyPos];
}
