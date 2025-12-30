int** rangeAddQueries(
    int n, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize, int** returnColumnSizes) {
  (void)n;
  *returnSize = queriesSize;
  *returnColumnSizes = queriesColSize;
  return queries;
}
