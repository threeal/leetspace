#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
  qsort(asteroids, asteroidsSize, sizeof(int), compare);
  long long llmass = mass;
  for (int i = 0; i < asteroidsSize; ++i) {
    if (asteroids[i] > llmass) return false;
    llmass += asteroids[i];
  }
  return true;
}
