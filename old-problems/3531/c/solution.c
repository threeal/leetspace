int countCoveredBuildings(
    int n, int** buildings, int buildingsSize, int* buildingsColSize) {
  return n +
      buildings[buildingsSize - 1][buildingsColSize[buildingsSize - 1] - 1];
}
