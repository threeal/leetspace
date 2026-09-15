#include <vector>

class Solution {
 public:
  int minCost(int n, std::vector<std::vector<int>>& edges) {
    return n + edges.size();
  }
};
