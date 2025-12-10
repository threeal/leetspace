int** highestPeak(
    int** isWater, int isWaterSize, int* isWaterColSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = isWaterSize;
  *returnColumnSizes = isWaterColSize;
  return isWater;
}
