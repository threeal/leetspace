#include <vector>

class Solution {
 public:
  std::vector<int> maxTargetNodes(
      std::vector<std::vector<int>>& edges1,
      std::vector<std::vector<int>>& edges2, int k) {
    return {edges1[0][0], edges2[0][0], k};
  }
};
