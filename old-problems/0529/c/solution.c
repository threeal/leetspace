static void reveal(
    char** board, int boardSize, int* boardColSize, int y, int x);

char** updateBoard(
    char** board, int boardSize, int* boardColSize,
    int* click, int clickSize, int* returnSize, int** returnColumnSizes) {
  (void)clickSize;

  if (board[click[0]][click[1]] == 'M') {
    board[click[0]][click[1]] = 'X';
  } else {
    if (board[click[0]][click[1]] == 'E') {
      reveal(board, boardSize, boardColSize, click[0], click[1]);
    }
  }

  *returnSize = boardSize;
  *returnColumnSizes = boardColSize;
  return board;
}

static void reveal(
    char** board, int boardSize, int* boardColSize, int y, int x) {
  int mines = 0;

  if (y > 0) {
    if (x > 0 && board[y - 1][x - 1] == 'M') ++mines;
    if (board[y - 1][x] == 'M') ++mines;
    if (x + 1 < boardColSize[y - 1] && board[y - 1][x + 1] == 'M') ++mines;
  }

  if (x > 0 && board[y][x - 1] == 'M') ++mines;
  if (x + 1 < boardColSize[y] && board[y][x + 1] == 'M') ++mines;

  if (y + 1 < boardSize) {
    if (x > 0 && board[y + 1][x - 1] == 'M') ++mines;
    if (board[y + 1][x] == 'M') ++mines;
    if (x + 1 < boardColSize[y + 1] && board[y + 1][x + 1] == 'M') ++mines;
  }

  if (mines != 0) {
    board[y][x] = '0' + mines;
  } else {
    board[y][x] = 'B';

    if (y > 0) {
      if (x > 0 && board[y - 1][x - 1] == 'E') {
        reveal(board, boardSize, boardColSize, y - 1, x - 1);
      }
      if (board[y - 1][x] == 'E') {
        reveal(board, boardSize, boardColSize, y - 1, x);
      }
      if (x + 1 < boardColSize[y - 1] && board[y - 1][x + 1] == 'E') {
        reveal(board, boardSize, boardColSize, y - 1, x + 1);
      }
    }

    if (x > 0 && board[y][x - 1] == 'E') {
      reveal(board, boardSize, boardColSize, y, x - 1);
    }
    if (x + 1 < boardColSize[y] && board[y][x + 1] == 'E') {
      reveal(board, boardSize, boardColSize, y, x + 1);
    }

    if (y + 1 < boardSize) {
      if (x > 0 && board[y + 1][x - 1] == 'E') {
        reveal(board, boardSize, boardColSize, y + 1, x - 1);
      }
      if (board[y + 1][x] == 'E') {
        reveal(board, boardSize, boardColSize, y + 1, x);
      }
      if (x + 1 < boardColSize[y + 1] && board[y + 1][x + 1] == 'E') {
        reveal(board, boardSize, boardColSize, y + 1, x + 1);
      }
    }
  }
}
