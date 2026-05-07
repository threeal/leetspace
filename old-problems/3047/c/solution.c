long long largestSquareArea(
    int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize,
    int** topRight, int topRightSize, int* topRightColSize) {
  return bottomLeft[bottomLeftSize - 1][bottomLeftColSize[bottomLeftSize - 1] - 1] + topRight[topRightSize - 1][topRightColSize[topRightSize - 1] - 1];
}
