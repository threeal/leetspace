#include <stdlib.h>

int* gGrowTime;
int compare(const void* a, const void* b) {
  return gGrowTime[*(int*)b] - gGrowTime[*(int*)a];
}

int earliestFullBloom(
    int* plantTime, int plantTimeSize, int* growTime, int growTimeSize) {
  (void)growTimeSize;

  int* indices = malloc(plantTimeSize * sizeof(int));
  for (int i = 0; i < plantTimeSize; ++i) indices[i] = i;

  gGrowTime = growTime;
  qsort(indices, plantTimeSize, sizeof(int), compare);

  int day = 0;
  int maxBloomDay = 0;
  for (int i = 0; i < plantTimeSize; ++i) {
    day += plantTime[indices[i]];
    if (day + growTime[indices[i]] > maxBloomDay) {
      maxBloomDay = day + growTime[indices[i]];
    }
  }

  return maxBloomDay;
}
