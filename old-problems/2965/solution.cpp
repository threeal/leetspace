#include <vector>

class Solution {
 public:
  std::vector<int> findMissingAndRepeatedValues(
      std::vector<std::vector<int>>& grid) {
    int repeated{};
    std::vector<bool> exists(grid.size() * grid.size() + 1, false);

    for (const auto& row : grid) {
      for (const auto val : row) {
        if (exists[val]) {
          repeated = val;
        } else {
          exists[val] = true;
        }
      }
    }

    int missing{};
    for (std::size_t val{1}; val < exists.size(); ++val) {
      if (!exists[val]) {
        missing = val;
        break;
      }
    }

    return {repeated, missing};
  }
};
