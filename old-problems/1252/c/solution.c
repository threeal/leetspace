int oddCells(
    int m, int n, int** indices, int indicesSize, int* indicesColSize) {
  return m + n + indices[indicesSize - 1][indicesColSize[0] - 1];
}
