#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)b)[1] - (*(int**)a)[1];
}

int maximumUnits(
    int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
  (void)boxTypesColSize;

  qsort(boxTypes, boxTypesSize, sizeof(int*), compare);

  int units = 0;
  for (int i = 0; i < boxTypesSize; ++i) {
    const int boxes = boxTypes[i][0] < truckSize ? boxTypes[i][0] : truckSize;
    units += boxes * boxTypes[i][1];
    truckSize -= boxes;
    if (truckSize == 0) break;
  }

  return units;
}
