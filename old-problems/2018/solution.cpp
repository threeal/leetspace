#include <algorithm>
#include <list>
#include <string>
#include <vector>

class Solution {
 public:
  bool placeWordInCrossword(
      std::vector<std::vector<char>>& board, std::string word) {
    auto reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());

    for (int y = board.size() - 1; y >= 0; --y) {
      int x = board.front().size() - 1;
      while (x >= 0) {
        while (x >= 0 && board[y][x] == '#') --x;

        if (x < static_cast<int>(word.size() - 1)) break;

        int i = word.size() - 1;
        while (i >= 0) {
          if (board[y][x - i] != ' ' && board[y][x - i] != word[i]) break;
          --i;
        }
        if (i < 0) {
          if (x - word.size() + 1 == 0) return true;
          if (board[y][x - word.size()] == '#') return true;
        }

        i = word.size() - 1;
        while (i >= 0) {
          if (board[y][x - i] != ' ' && board[y][x - i] != reversedWord[i]) break;
          --i;
        }
        if (i < 0) {
          if (x - word.size() + 1 == 0) return true;
          if (board[y][x - word.size()] == '#') return true;
        }

        while (x >= 0 && board[y][x] != '#') --x;
      }
    }

    for (int x = board.front().size() - 1; x >= 0; --x) {
      int y = board.size() - 1;
      while (y >= 0) {
        while (y >= 0 && board[y][x] == '#') --y;

        if (y < static_cast<int>(word.size() - 1)) break;

        int i = word.size() - 1;
        while (i >= 0) {
          if (board[y - i][x] != ' ' && board[y - i][x] != word[i]) break;
          --i;
        }
        if (i < 0) {
          if (y - word.size() + 1 == 0) return true;
          if (board[y - word.size()][x] == '#') return true;
        }

        i = word.size() - 1;
        while (i >= 0) {
          if (board[y - i][x] != ' ' && board[y - i][x] != reversedWord[i]) break;
          --i;
        }
        if (i < 0) {
          if (y - word.size() + 1 == 0) return true;
          if (board[y - word.size()][x] == '#') return true;
        }

        while (y >= 0 && board[y][x] != '#') --y;
      }
    }

    return false;
  }
};
