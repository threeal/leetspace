#include <vector>

class Solution {
 public:
  std::vector<int> minimumCost(
      int n, std::vector<std::vector<int>>& edges,
      std::vector<std::vector<int>>& query) {
    return std::vector<int>(query.size(), n + edges.size());
  }
};
