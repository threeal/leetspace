int** queensAttacktheKing(
    int** queens, int queensSize, int* queensColSize, int* king, int kingSize,
    int* returnSize, int** returnColumnSizes) {
  (void)king;
  (void)kingSize;
  *returnSize = queensSize;
  *returnColumnSizes = queensColSize;
  return queens;
}
