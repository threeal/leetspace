static int backtrack(int n, int* board, int i);

int totalNQueens(int n) {
  int board[10] = {0};
  return backtrack(n, board, 0);
}

static int backtrack(int n, int* board, int i) {
  int count = 0;
  for (int j = 0; j < n; ++j) {
    int ok = 1;
    for (int k = i - 1, l = j - 1, r = j + 1; k >= 0; --k, --l, ++r) {
      if (board[k] & (1 << j)) {
        ok = 0;
        break;
      }

      if (l >= 0 && (board[k] & (1 << l))) {
        ok = 0;
        break;
      }

      if (r < n && (board[k] & (1 << r))) {
        ok = 0;
        break;
      }
    }
    if (!ok) continue;

    board[i] |= 1 << j;
    count += i == n - 1 ? 1 : backtrack(n, board, i + 1);
    board[i] &= ~(1 << j);
  }
  return count;
}
