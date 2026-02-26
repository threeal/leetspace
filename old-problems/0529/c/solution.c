char** updateBoard(
    char** board, int boardSize, int* boardColSize,
    int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
  (void)click;
  (void)clickSize;
  *returnSize = boardSize;
  *returnColumnSizes = boardColSize;
  return board;
}
