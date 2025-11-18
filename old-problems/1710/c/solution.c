int maximumUnits(
    int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
  return boxTypes[boxTypesSize - 1][boxTypesColSize[boxTypesSize - 1] - 1] +
      truckSize;
}
