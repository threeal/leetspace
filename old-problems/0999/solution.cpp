#include <vector>

class Solution {
 public:
  int numRookCaptures(std::vector<std::vector<char>>& board) {
    std::size_t ry{0}, rx{0};
    while (ry < board.size()) {
      rx = 0;
      while (rx < board[ry].size() && board[ry][rx] != 'R') ++rx;

      if (rx < board[ry].size()) {
        break;
      } else {
        ++ry;
      }
    }

    int captures{0};

    for (std::size_t y{ry + 1}; y < board.size(); ++y) {
      switch (board[y][rx]) {
        case 'p':
          ++captures;

        case 'B':
          y = board.size();
          break;
      }
    }

    for (std::size_t y{ry}; y > 0; --y) {
      switch (board[y - 1][rx]) {
        case 'p':
          ++captures;

        case 'B':
          y = 1;
          break;
      }
    }

    for (std::size_t x{rx + 1}; x < board[ry].size(); ++x) {
      switch (board[ry][x]) {
        case 'p':
          ++captures;

        case 'B':
          x = board[ry].size();
          break;
      }
    }

    for (std::size_t x{rx}; x > 0; --x) {
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
};
