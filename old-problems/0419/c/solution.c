int countBattleships(char** board, int boardSize, int* boardColSize) {
  int count = 0;

  if (board[0][0] == 'X') ++count;

  for (int i = 1; i < boardColSize[0]; ++i) {
    if (board[0][i] == 'X' && board[0][i - 1] == '.') ++count;
  }

  for (int i = 1; i < boardSize; ++i) {
    if (board[i][0] == 'X' && board[i - 1][0] == '.') ++count;

    for (int j = 1; j < boardColSize[i]; ++j) {
      if (
          board[i][j] == 'X' &&
          board[i - 1][j] == '.' &&
          board[i][j - 1] == '.') ++count;
    }
  }

  return count;
}
