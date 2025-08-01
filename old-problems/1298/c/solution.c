#include <stdlib.h>

int maxCandies(
    int* status, int statusSize,
    int* candies, int candiesSize,
    int** keys, int keysSize, int* keysColSize,
    int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize,
    int* initialBoxes, int initialBoxesSize) {
  (void)candiesSize;
  (void)keysSize;
  (void)containedBoxesSize;

  int* boxes = malloc(statusSize * sizeof(int));
  int boxesSize = 0;

  for (int i = 0; i < initialBoxesSize; ++i) {
    if ((status[initialBoxes[i]] |= 2) == 3) {
      status[initialBoxes[i]] |= 4;
      boxes[boxesSize++] = initialBoxes[i];
    }
  }

  int totalCandies = 0;
  for (int i = 0; i < boxesSize; ++i) {
    totalCandies += candies[boxes[i]];

    for (int j = 0; j < keysColSize[boxes[i]]; ++j) {
      if ((status[keys[boxes[i]][j]] |= 1) == 3) {
        status[keys[boxes[i]][j]] |= 4;
        boxes[boxesSize++] = keys[boxes[i]][j];
      }
    }

    for (int j = 0; j < containedBoxesColSize[boxes[i]]; ++j) {
      if ((status[containedBoxes[boxes[i]][j]] |= 2) == 3) {
        status[containedBoxes[boxes[i]][j]] |= 4;
        boxes[boxesSize++] = containedBoxes[boxes[i]][j];
      }
    }
  }

  free(boxes);
  return totalCandies;
}
