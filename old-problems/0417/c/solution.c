int** pacificAtlantic(
    int** heights, int heightsSize, int* heightsColSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = heightsSize;
  *returnColumnSizes = heightsColSize;
  return heights;
}
