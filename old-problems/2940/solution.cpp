#include <vector>

class Solution {
 public:
  std::vector<int> leftmostBuildingQueries(
      std::vector<int>& heights, std::vector<std::vector<int>>& queries) {
    return std::vector(queries.size(), heights.front());
  }
};
