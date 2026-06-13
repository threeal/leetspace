#include <algorithm>
#include <vector>

class Solution {
 public:
  int minPathCost(
      std::vector<std::vector<int>>& grid,
      std::vector<std::vector<int>>& moveCost) {
    std::vector<int> now{grid[0]}, prev(now.size());
    for (std::size_t i{1}; i < grid.size(); ++i) {
      std::swap(now, prev);
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        int minCost{prev[0] + moveCost[grid[i - 1][0]][j]};
        for (std::size_t k{1}; k < grid[i].size(); ++k) {
          const int cost{prev[k] + moveCost[grid[i - 1][k]][j]};
          if (cost < minCost) minCost = cost;
        }
        now[j] = grid[i][j] + minCost;
      }
    }
    return *std::min_element(now.begin(), now.end());
  }
};
