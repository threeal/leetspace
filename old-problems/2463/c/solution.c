long long minimumTotalDistance(
    int* robot, int robotSize,
    int** factory, int factorySize, int* factoryColSize) {
  return robot[robotSize - 1] *
      factory[factorySize - 1][factoryColSize[factorySize - 1] - 1];
}
