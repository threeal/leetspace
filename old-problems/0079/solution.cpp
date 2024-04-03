#include <string>
#include <string_view>
#include <vector>

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    const std::string_view wordView(word);
    for (std::size_t y{0}; y < board.size(); ++y) {
      for (std::size_t x{0}; x < board[y].size(); ++x) {
        if (board[y][x] == wordView[0] && checkExistRecursively(board, wordView.substr(1), y, x)) return true;
      }
    }

    return false;
  }

  bool checkExistRecursively(std::vector<std::vector<char>>& board, std::string_view word, std::size_t y, std::size_t x) {
    if (word.empty()) return true;

    const char tmp{board[y][x]};
    board[y][x] = 0;

    if (y > 0 && board[y - 1][x] == word[0] && checkExistRecursively(board, word.substr(1), y - 1, x)) return true;
    if (y < board.size() - 1 && board[y + 1][x] == word[0] && checkExistRecursively(board, word.substr(1), y + 1, x)) return true;
    if (x > 0 && board[y][x - 1] == word[0] && checkExistRecursively(board, word.substr(1), y, x - 1)) return true;
    if (x < board[y].size() - 1 && board[y][x + 1] == word[0] && checkExistRecursively(board, word.substr(1), y, x + 1)) return true;

    board[y][x] = tmp;
    return false;
  }
};
