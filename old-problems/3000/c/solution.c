int areaOfMaxDiagonal(
    int** dimensions, int dimensionsSize, int* dimensionsColSize) {
  return dimensions[dimensionsSize - 1][dimensionsColSize[dimensionsSize - 1] - 1];
}
