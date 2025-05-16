#include <stdlib.h>

int* gPositions;
int comparePositions(const void* a, const void* b) {
  return gPositions[*(int*)a] - gPositions[*(int*)b];
}

int* survivedRobotsHealths(
    int* positions, int positionsSize,
    int* healths, int healthsSize,
    char* directions, int* returnSize) {
  int* indexes = malloc(positionsSize * sizeof(int));
  for (int i = positionsSize - 1; i >= 0; --i) {
    indexes[i] = i;
  }

  gPositions = positions;
  qsort(indexes, positionsSize, sizeof(int), comparePositions);

  int* rights = malloc(positionsSize * sizeof(int));
  int rightsSize = 0;

  for (int i = 0; i < positionsSize; ++i) {
    if (directions[indexes[i]] == 'R') {
      rights[rightsSize++] = indexes[i];
    } else {
      while (rightsSize != 0 && healths[indexes[i]] > 0) {
        if (healths[indexes[i]] >= healths[rights[rightsSize - 1]]) {
          if (healths[indexes[i]] == healths[rights[rightsSize - 1]]) {
            healths[indexes[i]] = 0;
          } else {
            --healths[indexes[i]];
          }
          healths[rights[rightsSize - 1]] = 0;
          --rightsSize;
        } else {
          --healths[rights[rightsSize - 1]];
          healths[indexes[i]] = 0;
        }
      }
    }
  }

  int outputSize = 0;
  for (int i = 0; i < healthsSize; ++i) {
    if (healths[i] == 0) continue;
    healths[outputSize++] = healths[i];
  }

  free(indexes);
  free(rights);

  *returnSize = outputSize;
  return healths;
}
