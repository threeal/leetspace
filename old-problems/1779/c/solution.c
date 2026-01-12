int nearestValidPoint(
    int x, int y, int** points, int pointsSize, int* pointsColSize) {
  return x + y + points[pointsSize - 1][pointsColSize[pointsSize - 1] - 1];
}
