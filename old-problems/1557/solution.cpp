#include <vector>

class Solution {
 public:
  std::vector<int> findSmallestSetOfVertices(
      int n, std::vector<std::vector<int>>& edges) {
    std::vector<bool> exists(n);
    for (const std::vector<int>& edge : edges) {
      exists[edge[1]] = true;
    }

    std::vector<int> output{};
    for (int i{0}; i < n; ++i) {
      if (!exists[i]) output.push_back(i);
    }

    return output;
  }
};
