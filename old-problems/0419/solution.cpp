#include <vector>

class Solution {
 public:
  int countBattleships(std::vector<std::vector<char>>& board) {
    int count{0};

    if (board[0][0] == 'X') ++count;

    for (std::size_t i{1}; i < board[0].size(); ++i) {
      if (board[0][i] == 'X' && board[0][i - 1] == '.') ++count;
    }

    for (std::size_t i{1}; i < board.size(); ++i) {
      if (board[i][0] == 'X' && board[i - 1][0] == '.') ++count;

      for (std::size_t j{1}; j < board[i].size(); ++j) {
        if (
            board[i][j] == 'X' &&
            board[i - 1][j] == '.' &&
            board[i][j - 1] == '.') ++count;
      }
    }

    return count;
  }
};
