int** highestPeak(
    int** isWater, int isWaterSize, int* isWaterColSize,
    int* returnSize, int** returnColumnSizes) {
  isWater[0][0] = isWater[0][0] == 0 ? 10000 : 0;
  for (int j = 1; j < isWaterColSize[0]; ++j) {
    isWater[0][j] = isWater[0][j] == 0 ? isWater[0][j - 1] + 1 : 0;
  }

  for (int i = 1; i < isWaterSize; ++i) {
    isWater[i][0] = isWater[i][0] == 0 ? isWater[i - 1][0] + 1 : 0;
    for (int j = 1; j < isWaterColSize[i]; ++j) {
      if (isWater[i][j] == 0) {
        isWater[i][j] = isWater[i - 1][j] + 1 <= isWater[i][j - 1] + 1
            ? isWater[i - 1][j] + 1
            : isWater[i][j - 1] + 1;
      } else {
        isWater[i][j] = 0;
      }
    }
  }

  for (int j = isWaterColSize[isWaterSize - 1] - 2; j >= 0; --j) {
    if (isWater[isWaterSize - 1][j + 1] + 1 < isWater[isWaterSize - 1][j]) {
      isWater[isWaterSize - 1][j] = isWater[isWaterSize - 1][j + 1] + 1;
    }
  }

  for (int i = isWaterSize - 2; i >= 0; --i) {
    if (isWater[i + 1][isWaterColSize[i + 1] - 1] + 1 <
        isWater[i][isWaterColSize[i] - 1]) {
      isWater[i][isWaterColSize[i] - 1] =
          isWater[i + 1][isWaterColSize[i + 1] - 1] + 1;
    }

    for (int j = isWaterColSize[i] - 2; j >= 0; --j) {
      const int min = isWater[i][j + 1] + 1 <= isWater[i + 1][j] + 1
          ? isWater[i][j + 1] + 1
          : isWater[i + 1][j] + 1;

      if (min < isWater[i][j]) isWater[i][j] = min;
    }
  }

  *returnSize = isWaterSize;
  *returnColumnSizes = isWaterColSize;
  return isWater;
}
