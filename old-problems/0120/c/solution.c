int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
  return triangle[triangleSize - 1][triangleColSize[triangleSize - 1] - 1];
}
