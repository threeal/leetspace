#include <numeric>
#include <vector>

class Solution {
 public:
  bool containsCycle(std::vector<std::vector<char>>& grid) {
    const std::size_t m{grid.size()}, n{grid[0].size()};

    std::vector<std::size_t> roots(m * n);
    std::iota(roots.begin(), roots.end(), 0);

    for (std::size_t i{0}; i < m; ++i) {
      for (std::size_t j{0}; j < n; ++j) {
        if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
          const std::size_t a{findRoot(roots, i * n + j)};
          const std::size_t b{findRoot(roots, (i + 1) * n + j)};
          if (a == b) return true;
          if (a < b) {
            roots[b] = a;
          } else {
            roots[a] = b;
          }
        }

        if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
          const std::size_t a{findRoot(roots, i * n + j)};
          const std::size_t b{findRoot(roots, i * n + j + 1)};
          if (a == b) return true;
          if (a < b) {
            roots[b] = a;
          } else {
            roots[a] = b;
          }
        }
      }
    }
    return false;
  }

  static std::size_t findRoot(std::vector<std::size_t>& roots, std::size_t i) {
    return roots[i] != i ? (roots[i] = findRoot(roots, roots[i])) : i;
  }
};
