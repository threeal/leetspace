#include <map>
#include <vector>

class Solution {
 public:
  int equalPairs(std::vector<std::vector<int>>& grid) {
    std::map<std::vector<int>, int> freqs{};
    for (const auto& row : grid) ++freqs[row];

    int count{0};
    std::vector<int> column(grid.size());
    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid.size(); ++j) {
        column[j] = grid[j][i];
      }

      const auto it = freqs.find(column);
      if (it != freqs.end()) count += it->second;
    }

    return count;
  }
};
