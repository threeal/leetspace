int* findSmallestSetOfVertices(
    int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
  (void)n;
  *returnSize = edgesColSize[edgesSize - 1];
  return edges[edgesSize - 1];
}
