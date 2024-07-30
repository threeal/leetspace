int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
  for (int i = 1; i < triangleSize; ++i) {
    triangle[i][0] += triangle[i - 1][0];
    for (int j = triangleColSize[i] - 2; j > 0; --j) {
      triangle[i][j] += triangle[i - 1][j - 1] < triangle[i - 1][j]
          ? triangle[i - 1][j - 1]
          : triangle[i - 1][j];
    }
    triangle[i][triangleColSize[i] - 1] +=
        triangle[i - 1][triangleColSize[i - 1] - 1];
  }

  int min = triangle[triangleSize - 1][0];
  for (int i = triangleColSize[triangleSize - 1] - 1; i > 0; --i) {
    if (triangle[triangleSize - 1][i] < min) {
      min = triangle[triangleSize - 1][i];
    }
  }

  return min;
}
