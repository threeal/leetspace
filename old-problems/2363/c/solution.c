int** mergeSimilarItems(
    int** items1, int items1Size, int* items1ColSize,
    int** items2, int items2Size, int* items2ColSize,
    int* returnSize, int** returnColumnSizes) {
  (void)items2;
  (void)items2Size;
  (void)items2ColSize;
  *returnSize = items1Size;
  *returnColumnSizes = items1ColSize;
  return items1;
}
