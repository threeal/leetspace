#include <stdbool.h>

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
  (void)movesColSize;

  char board[3][3] = {
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}};

  bool aTurn = true;
  for (int i = 0; i < movesSize; ++i) {
    board[moves[i][0]][moves[i][1]] = aTurn ? 'A' : 'B';
    aTurn = !aTurn;
  }

  if (board[0][0] != 0) {
    if ((board[0][0] == board[0][1] && board[0][1] == board[0][2]) ||
        (board[0][0] == board[1][0] && board[1][0] == board[2][0])) {
      return board[0][0] == 'A' ? "A" : "B";
    }
  }

  if (board[1][1] != 0) {
    if ((board[1][0] == board[1][1] && board[1][1] == board[1][2]) ||
        (board[0][1] == board[1][1] && board[1][1] == board[2][1]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
      return board[1][1] == 'A' ? "A" : "B";
    }
  }

  if (board[2][2] != 0) {
    if ((board[2][0] == board[2][1] && board[2][1] == board[2][2]) ||
        (board[0][2] == board[1][2] && board[1][2] == board[2][2])) {
      return board[2][2] == 'A' ? "A" : "B";
    }
  }

  return movesSize == 9 ? "Draw" : "Pending";
}
