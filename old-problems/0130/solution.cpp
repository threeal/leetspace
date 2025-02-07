#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    for (std::size_t y{0}; y < board.size(); ++y) {
      if (board[y][0] == 'O') markRegions(board, y, 0);

      if (board[y][board[y].size() - 1] == 'O')
        markRegions(board, y, board[y].size() - 1);
    }

    for (std::size_t x{0}; x < board[0].size() - 1; ++x) {
      if (board[0][x] == 'O') markRegions(board, 0, x);

      if (board[board.size() - 1][x] == 'O')
        markRegions(board, board.size() - 1, x);
    }

    for (std::size_t y{0}; y < board.size(); ++y) {
      for (std::size_t x{0}; x < board[y].size(); ++x) {
        if (board[y][x] == 'O')
          board[y][x] = 'X';
        else if (board[y][x] == 0)
          board[y][x] = 'O';
      }
    }
  }

 private:
  void markRegions(
      std::vector<std::vector<char>>& board, std::size_t y, std::size_t x) {
    board[y][x] = 0;

    if (y > 0 && board[y - 1][x] == 'O') markRegions(board, y - 1, x);
    if (x > 0 && board[y][x - 1] == 'O') markRegions(board, y, x - 1);

    if (y < board.size() - 1 && board[y + 1][x] == 'O')
      markRegions(board, y + 1, x);

    if (x < board[y].size() - 1 && board[y][x + 1] == 'O')
      markRegions(board, y, x + 1);
  }
};
