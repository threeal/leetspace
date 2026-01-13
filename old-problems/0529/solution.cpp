#include <vector>

class Solution {
 public:
  std::vector<std::vector<char>> updateBoard(
      std::vector<std::vector<char>>& board, std::vector<int>& click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
    } else {
      if (board[click[0]][click[1]] == 'E') {
        reveal(board, click[0], click[1]);
      }
    }
    return board;
  }

 private:
  static void reveal(
      std::vector<std::vector<char>>& board, std::size_t y, std::size_t x) {
    int mines{0};

    if (y > 0) {
      if (x > 0 && board[y - 1][x - 1] == 'M') ++mines;
      if (board[y - 1][x] == 'M') ++mines;
      if (x + 1 < board[y - 1].size() && board[y - 1][x + 1] == 'M') ++mines;
    }

    if (x > 0 && board[y][x - 1] == 'M') ++mines;
    if (x + 1 < board[y].size() && board[y][x + 1] == 'M') ++mines;

    if (y + 1 < board.size()) {
      if (x > 0 && board[y + 1][x - 1] == 'M') ++mines;
      if (board[y + 1][x] == 'M') ++mines;
      if (x + 1 < board[y + 1].size() && board[y + 1][x + 1] == 'M') ++mines;
    }

    if (mines != 0) {
      board[y][x] = '0' + mines;
    } else {
      board[y][x] = 'B';

      if (y > 0) {
        if (x > 0 && board[y - 1][x - 1] == 'E') reveal(board, y - 1, x - 1);
        if (board[y - 1][x] == 'E') reveal(board, y - 1, x);
        if (x + 1 < board[y - 1].size() && board[y - 1][x + 1] == 'E') {
          reveal(board, y - 1, x + 1);
        }
      }

      if (x > 0 && board[y][x - 1] == 'E') reveal(board, y, x - 1);
      if (x + 1 < board[y].size() && board[y][x + 1] == 'E') {
        reveal(board, y, x + 1);
      }

      if (y + 1 < board.size()) {
        if (x > 0 && board[y + 1][x - 1] == 'E') reveal(board, y + 1, x - 1);
        if (board[y + 1][x] == 'E') reveal(board, y + 1, x);
        if (x + 1 < board[y + 1].size() && board[y + 1][x + 1] == 'E') {
          reveal(board, y + 1, x + 1);
        }
      }
    }
  }
};
