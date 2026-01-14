int numRookCaptures(char** board, int boardSize, int* boardColSize) {
  int ry = 0, rx = 0;
  while (ry < boardSize) {
    rx = 0;
    while (rx < boardColSize[ry] && board[ry][rx] != 'R') ++rx;

    if (rx < boardColSize[ry]) {
      break;
    } else {
      ++ry;
    }
  }

  int captures = 0;

  for (int y = ry + 1; y < boardSize; ++y) {
    switch (board[y][rx]) {
      case 'p':
        ++captures;

      case 'B':
        y = boardSize;
        break;
    }
  }

  for (int y = ry; y > 0; --y) {
    switch (board[y - 1][rx]) {
      case 'p':
        ++captures;

      case 'B':
        y = 1;
        break;
    }
  }

  for (int x = rx + 1; x < boardColSize[ry]; ++x) {
    switch (board[ry][x]) {
      case 'p':
        ++captures;

      case 'B':
        x = boardColSize[ry];
        break;
    }
  }

  for (int x = rx; x > 0; --x) {
    switch (board[ry][x - 1]) {
      case 'p':
        ++captures;

      case 'B':
        x = 1;
        break;
    }
  }

  return captures;
}
