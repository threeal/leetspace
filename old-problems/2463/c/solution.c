#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int compareFactory(const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

static long long recursiveMinimumTotalDistance(
    int* robot, int robotSize, int** factory, int factorySize,
    long long** cache, int robotIdx, int factoryIdx);

long long minimumTotalDistance(
    int* robot, int robotSize,
    int** factory, int factorySize, int* factoryColSize) {
  qsort(robot, robotSize, sizeof(int), compare);
  qsort(factory, factorySize, sizeof(int*), compareFactory);

  long long** cache = malloc(factorySize * sizeof(long long*));
  for (int i = 0; i < factorySize; ++i) {
    cache[i] = malloc(robotSize * sizeof(long long));
    for (int j = 0; j < robotSize; ++j) cache[i][j] = -1;
  }

  const long long res = recursiveMinimumTotalDistance(
      robot, robotSize, factory, factorySize, cache, 0, 0);

  for (int i = 0; i < factorySize; ++i) free(cache[i]);
  free(cache);

  return res;

  return robot[robotSize - 1] *
      factory[factorySize - 1][factoryColSize[factorySize - 1] - 1];
}

static long long recursiveMinimumTotalDistance(
    int* robot, int robotSize, int** factory, int factorySize,
    long long** cache, int robotIdx, int factoryIdx) {
  if (factoryIdx == factorySize) return robotIdx == robotSize ? 0 : -1;
  if (robotIdx == robotSize) return 0;

  if (cache[factoryIdx][robotIdx] < 0) {
    long long minDistance = recursiveMinimumTotalDistance(
        robot, robotSize, factory, factorySize,
        cache, robotIdx, factoryIdx + 1);

    long long distance = 0;
    for (int i = 0; i < factory[factoryIdx][1]; ++i) {
      if (robotIdx + i == robotSize) break;
      distance += abs(factory[factoryIdx][0] - robot[robotIdx + i]);
      const long long restDistance = recursiveMinimumTotalDistance(
          robot, robotSize, factory, factorySize,
          cache, robotIdx + i + 1, factoryIdx + 1);
      if (restDistance < 0) continue;
      if (minDistance < 0 || distance + restDistance < minDistance) {
        minDistance = distance + restDistance;
      }
    }

    cache[factoryIdx][robotIdx] = minDistance;
  }

  return cache[factoryIdx][robotIdx];
}
