#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> queensAttacktheKing(
      std::vector<std::vector<int>>& queens, std::vector<int>& king) {
    std::vector<std::vector<bool>> board(8, std::vector<bool>(8, false));
    for (const auto& queen : queens) {
      board[queen[0]][queen[1]] = true;
    }

    std::size_t n{0};
    for (int i{king[0]}, j{king[1]}; i < 8; ++i) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; i < 8 && j < 8; ++i, ++j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; j < 8; ++j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; i >= 0 && j < 8; --i, ++j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; i >= 0; --i) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; j >= 0; --j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    for (int i{king[0]}, j{king[1]}; i < 8 && j >= 0; ++i, --j) {
      if (board[i][j]) {
        queens[n++] = {i, j};
        break;
      }
    }

    queens.resize(n);
    return queens;
  }
};
