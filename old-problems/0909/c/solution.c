#include <stdlib.h>

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
  (void)boardColSize;

  const int n = boardSize;
  const int end = n * n - 1;

  int* positions = malloc(n * n * sizeof(int));

  positions[0] = 0;
  int positionsBegin = 0;
  int positionsEnd = 1;

  for (int moves = 1; positionsBegin < positionsEnd; ++moves) {
    int newPositionsEnd = positionsEnd;
    for (int i = positionsBegin; i < positionsEnd; ++i) {
      const int pos = positions[i];

      if (pos + 6 >= end) return moves;
      for (int next = pos + 6; next > pos; --next) {
        const int y = n - 1 - next / n;
        const int x = (next / n) % 2 == 0 ? next % n : n - 1 - next % n;
        if (board[y][x] > 0) {
          const int next = board[y][x] - 1;
          board[y][x] = 0;
          if (next == end) return moves;
          positions[newPositionsEnd] = next;
          ++newPositionsEnd;
        } else if (board[y][x] < 0) {
          board[y][x] = 0;
          positions[newPositionsEnd] = next;
          ++newPositionsEnd;
        }
      }
    }

    positionsBegin = positionsEnd;
    positionsEnd = newPositionsEnd;
  }

  return -1;
}
