int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
  return n * edges[edgesSize - 1][edgesColSize[edgesSize - 1]];
}
