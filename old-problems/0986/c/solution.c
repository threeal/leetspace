int** intervalIntersection(
    int** firstList, int firstListSize, int* firstListColSize,
    int** secondList, int secondListSize, int* secondListColSize,
    int* returnSize, int** returnColumnSizes) {
  if (firstListSize < secondListSize) {
    *returnSize = firstListSize;
    *returnColumnSizes = firstListColSize;
    return firstList;
  }

  *returnSize = secondListSize;
  *returnColumnSizes = secondListColSize;
  return secondList;
}
