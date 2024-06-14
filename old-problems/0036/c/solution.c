#include <stdbool.h>
#include <stdint.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
  (void)boardSize;
  (void)boardColSize;

  uint16_t exists = 0;
  for (int i = 8; i >= 0; --i) {
    exists = 0;
    for (int j = 8; j >= 0; --j) {
      if (board[i][j] == '.') continue;
      if ((exists >> (board[i][j] - '1') & 1) == 1) return false;
      exists |= 1 << (board[i][j] - '1');
    }

    exists = 0;
    for (int j = 8; j >= 0; --j) {
      if (board[j][i] == '.') continue;
      if ((exists >> (board[j][i] - '1') & 1) == 1) return false;
      exists |= 1 << (board[j][i] - '1');
    }
  }

  for (int i = 6; i >= 0; i -= 3) {
    for (int j = 6; j >= 0; j -= 3) {
      exists = 0;
      for (int ii = 2; ii >= 0; --ii) {
        for (int jj = 2; jj >= 0; --jj) {
          if (board[i + ii][j + jj] == '.') continue;
          if ((exists >> (board[i + ii][j + jj] - '1') & 1) == 1) return false;
          exists |= 1 << (board[i + ii][j + jj] - '1');
        }
      }
    }
  }

  return true;
}
