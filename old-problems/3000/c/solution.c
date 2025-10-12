int areaOfMaxDiagonal(
    int** dimensions, int dimensionsSize, int* dimensionsColSize) {
  (void)dimensionsColSize;
  int maxDiagonal = 0, maxArea = 0;
  for (int i = 0; i < dimensionsSize; ++i) {
    const int diagonal =
        dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];

    if (diagonal >= maxDiagonal) {
      const int area = dimensions[i][0] * dimensions[i][1];
      if (diagonal > maxDiagonal) {
        maxDiagonal = diagonal;
        maxArea = area;
      } else if (area > maxArea) {
        maxArea = area;
      }
    }
  }
  return maxArea;
}
