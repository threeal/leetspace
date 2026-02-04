#include <stdbool.h>

bool mergeTriplets(
    int** triplets, int tripletsSize, int* tripletsColSize,
    int* target, int targetSize) {
  return triplets[tripletsSize - 1][tripletsColSize[tripletsSize - 1] - 1] ==
      target[targetSize - 1];
}
