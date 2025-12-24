#include <stdint.h>

int** queensAttacktheKing(
    int** queens, int queensSize, int* queensColSize, int* king, int kingSize,
    int* returnSize, int** returnColumnSizes) {
  (void)kingSize;

  uint8_t board[8] = {0};
  for (int i = 0; i < queensSize; ++i) {
    board[queens[i][0]] |= 1 << queens[i][1];
  }

  int n = 0;
  for (int i = king[0], j = king[1]; i < 8; ++i) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; i < 8 && j < 8; ++i, ++j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; j < 8; ++j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; i >= 0 && j < 8; --i, ++j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; i >= 0; --i) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; i >= 0 && j >= 0; --i, --j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; j >= 0; --j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  for (int i = king[0], j = king[1]; i < 8 && j >= 0; ++i, --j) {
    if ((board[i] & (1 << j)) != 0) {
      queens[n][0] = i;
      queens[n++][1] = j;
      break;
    }
  }

  *returnSize = n;
  *returnColumnSizes = queensColSize;
  return queens;
}
