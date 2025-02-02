#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> output{};
    std::vector<std::string> grid(n, std::string(n, '.'));
    backtrack(output, n, grid, 0);
    return output;
  }

 private:
  static void backtrack(
      std::vector<std::vector<std::string>>& output, int n,
      std::vector<std::string>& grid, int i) {
    for (int j{0}; j < n; ++j) {
      bool ok{true};
      for (int k{i - 1}, l{j - 1}, r{j + 1}; k >= 0; --k, --l, ++r) {
        if (grid[k][j] == 'Q') {
          ok = false;
          break;
        }

        if (l >= 0 && grid[k][l] == 'Q') {
          ok = false;
          break;
        }

        if (r < n && grid[k][r] == 'Q') {
          ok = false;
          break;
        }
      }
      if (!ok) continue;

      grid[i][j] = 'Q';
      if (i == n - 1) {
        output.push_back(grid);
      } else {
        backtrack(output, n, grid, i + 1);
      }
      grid[i][j] = '.';
    }
  }
};
