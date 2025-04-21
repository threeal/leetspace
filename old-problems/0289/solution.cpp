#include <vector>

class Solution {
 public:
  void gameOfLife(std::vector<std::vector<int>>& board) {
    for (std::size_t i{0}; i < board.size(); ++i) {
      for (std::size_t j{0}; j < board[i].size(); ++j) {
        int neighbors{0};

        if (i > 0) {
          if (j > 0 && (board[i - 1][j - 1] & 1) == 1) ++neighbors;
          if ((board[i - 1][j] & 1) == 1) ++neighbors;

          if (j + 1 < board[i - 1].size() && (board[i - 1][j + 1] & 1) == 1) {
            ++neighbors;
          }
        }

        if (j > 0 && (board[i][j - 1] & 1) == 1) ++neighbors;
        if (j + 1 < board[i].size() && (board[i][j + 1] & 1) == 1) ++neighbors;

        if (i + 1 < board.size()) {
          if (j > 0 && (board[i + 1][j - 1] & 1) == 1) ++neighbors;
          if ((board[i + 1][j] & 1) == 1) ++neighbors;

          if (j + 1 < board[i + 1].size() && (board[i + 1][j + 1] & 1) == 1) {
            ++neighbors;
          }
        }

        if (neighbors == 3 || (neighbors == 2 && (board[i][j] & 1) == 1)) {
          board[i][j] |= 2;
        }
      }
    }

    for (std::size_t i{0}; i < board.size(); ++i) {
      for (std::size_t j{0}; j < board[i].size(); ++j) {
        board[i][j] >>= 1;
      }
    }
  }
};
