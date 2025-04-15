#include <vector>

class Solution {
 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    std::vector<std::vector<bool>> ye(9, std::vector(9, false));
    std::vector<std::vector<bool>> xe(9, std::vector(9, false));
    std::vector<std::vector<bool>> re(9, std::vector(9, false));

    for (int y{0}; y < 9; ++y) {
      for (int x{0}; x < 9; ++x) {
        if (board[y][x] != '.') {
          ye[y][board[y][x] - '1'] = true;
          xe[x][board[y][x] - '1'] = true;
          re[(y / 3) * 3 + x / 3][board[y][x] - '1'] = true;
        }
      }
    }

    solve(board.data(), ye.data(), xe.data(), re.data(), 0, 0);
  }

 private:
  static bool solve(
      std::vector<char>* board, std::vector<bool>* ye, std::vector<bool>* xe,
      std::vector<bool>* re, int y, int x) {
    if (board[y][x] != '.') {
      return x == 8
          ? (y == 8 ? true : solve(board, ye, xe, re, y + 1, 0))
          : solve(board, ye, xe, re, y, x + 1);
    }

    const int r{(y / 3) * 3 + x / 3};
    for (int i{0}; i < 9; ++i) {
      if (!ye[y][i] && !xe[x][i] && !re[r][i]) {
        board[y][x] = '1' + i;
        ye[y][i] = true;
        xe[x][i] = true;
        re[r][i] = true;

        if (x == 8) {
          if (y == 8) return true;
          if (solve(board, ye, xe, re, y + 1, 0)) return true;
        } else if (solve(board, ye, xe, re, y, x + 1)) {
          return true;
        }

        board[y][x] = '.';
        ye[y][i] = false;
        xe[x][i] = false;
        re[r][i] = false;
      }
    }

    return false;
  }
};
