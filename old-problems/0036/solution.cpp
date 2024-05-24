#include <algorithm>
#include <vector>

class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::vector<bool> exists(9);

    for (int i{8}; i >= 0; --i) {
      std::fill(exists.begin(), exists.end(), false);
      for (int j{8}; j >= 0; --j) {
        if (board[i][j] == '.') continue;
        if (exists[board[i][j] - '1']) return false;
        exists[board[i][j] - '1'] = true;
      }

      std::fill(exists.begin(), exists.end(), false);
      for (int j{8}; j >= 0; --j) {
        if (board[j][i] == '.') continue;
        if (exists[board[j][i] - '1']) return false;
        exists[board[j][i] - '1'] = true;
      }
    }

    for (int i{6}; i >= 0; i -= 3) {
      for (int j{6}; j >= 0; j -= 3) {
        std::fill(exists.begin(), exists.end(), false);
        for (int ii{2}; ii >= 0; --ii) {
          for (int jj{2}; jj >= 0; --jj) {
            if (board[i + ii][j + jj] == '.') continue;
            if (exists[board[i + ii][j + jj] - '1']) return false;
            exists[board[i + ii][j + jj] - '1'] = true;
          }
        }
      }
    }

    return true;
  }
};
