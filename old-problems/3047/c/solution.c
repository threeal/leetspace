long long largestSquareArea(
    int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize,
    int** topRight, int topRightSize, int* topRightColSize) {
  (void)bottomLeftColSize;
  (void)topRightColSize;
  int maxSide = 0;
  for (int i = 0; i < bottomLeftSize; ++i) {
    for (int j = i + 1; j < topRightSize; ++j) {
      const int width =
          (topRight[i][0] < topRight[j][0] ? topRight[i][0] : topRight[j][0]) -
          (bottomLeft[i][0] > bottomLeft[j][0] ? bottomLeft[i][0] : bottomLeft[j][0]);

      const int height =
          (topRight[i][1] < topRight[j][1] ? topRight[i][1] : topRight[j][1]) -
          (bottomLeft[i][1] > bottomLeft[j][1] ? bottomLeft[i][1] : bottomLeft[j][1]);

      const int side = width < height ? width : height;
      if (side > maxSide) maxSide = side;
    }
  }
  return (long long)maxSide * maxSide;
}
