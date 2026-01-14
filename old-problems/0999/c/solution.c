int numRookCaptures(char** board, int boardSize, int* boardColSize) {
  return board[boardSize - 1][boardColSize[boardSize - 1] - 1];
}
