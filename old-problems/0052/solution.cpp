#include <vector>

class Solution {
 public:
  int totalNQueens(int n) {
    std::vector<std::vector<bool>> board(n, std::vector(n, false));
    return backtrack(n, board, 0);
  }

 private:
  static int backtrack(int n, std::vector<std::vector<bool>>& board, int i) {
    int count{0};
    for (int j{0}; j < n; ++j) {
      bool ok{true};
      for (int k{i - 1}, l{j - 1}, r{j + 1}; k >= 0; --k, --l, ++r) {
        if (board[k][j]) {
          ok = false;
          break;
        }

        if (l >= 0 && board[k][l]) {
          ok = false;
          break;
        }

        if (r < n && board[k][r]) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;

      board[i][j] = true;
      count += i == n - 1 ? 1 : backtrack(n, board, i + 1);
      board[i][j] = false;
    }
    return count;
  }
};
