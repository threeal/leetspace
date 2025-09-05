#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int matchPlayersAndTrainers(
    int* players, int playersSize, int* trainers, int trainersSize) {
  qsort(players, playersSize, sizeof(int), compare);
  qsort(trainers, trainersSize, sizeof(int), compare);

  int i = 0, j = 0;
  while (i < playersSize && j < trainersSize) {
    while (j < trainersSize && players[i] > trainers[j]) ++j;
    if (j < trainersSize) ++i, ++j;
  }

  return i;
}
