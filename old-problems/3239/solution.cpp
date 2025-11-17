#include <vector>

class Solution {
 public:
  int minFlips(std::vector<std::vector<int>>& grid) {
    int rowInvalids{0};
    for (const auto& row : grid) {
      for (std::size_t l{0}, r{row.size() - 1}; l < r; ++l, --r) {
        if (row[l] != row[r]) ++rowInvalids;
      }
    }

    int colInvalids{0};
    for (std::size_t i{0}; i < grid[0].size(); ++i) {
      for (std::size_t l{0}, r{grid.size() - 1}; l < r; ++l, --r) {
        if (grid[l][i] != grid[r][i]) ++colInvalids;
      }
    }

    return rowInvalids <= colInvalids ? rowInvalids : colInvalids;
  }
};
