int findCenter(int** edges, int edgesSize, int* edgesColSize) {
  return edges[edgesSize - 1][edgesColSize[edgesSize - 1] - 1];
}
