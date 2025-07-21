int countGoodRectangles(
    int** rectangles, int rectanglesSize, int* rectanglesColSize) {
  const int j = rectanglesColSize[rectanglesSize - 1] - 1;
  return rectangles[rectanglesSize - 1][j];
}
