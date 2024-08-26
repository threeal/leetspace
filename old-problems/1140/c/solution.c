#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int32_t* pickPiles(int64_t** caches, int* piles, int pilesSize, int i, int m);

int stoneGameII(int* piles, int pilesSize) {
  int64_t** caches = malloc((pilesSize + 1) * sizeof(int64_t*));
  for (int i = pilesSize; i >= 0; --i) {
    caches[i] = malloc((pilesSize + 1) * sizeof(int64_t));
    memset(caches[i], -1, (pilesSize + 1) + sizeof(int64_t));
  }

  const int res = pickPiles(caches, piles, pilesSize, 0, 1)[0];

  for (int i = pilesSize; i >= 0; --i) free(caches[i]);
  free(caches);

  return res;
}

int32_t* pickPiles(int64_t** caches, int* piles, int pilesSize, int i, int m) {
  int32_t* best = (int32_t*)(caches[i] + m - 1);
  if (best[0] >= 0) return best;

  *(int64_t*)best = 0;

  int stones = 0;
  for (int j = 0; j < m * 2 && i + j < pilesSize; ++j) {
    stones += piles[i + j];
    const int32_t* current =
        pickPiles(caches, piles, pilesSize, i + j + 1, m > j + 1 ? m : j + 1);

    if (stones + current[1] > best[0]) {
      best[0] = stones + current[1];
      best[1] = current[0];
    }
  }

  return best;
}
