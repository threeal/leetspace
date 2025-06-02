#include <vector>

class Solution {
 public:
  std::vector<int> maxTargetNodes(
      std::vector<std::vector<int>>& edges1,
      std::vector<std::vector<int>>& edges2) {
    return edges1.size() >= edges2.size() ? edges1[0] : edges2[0];
  }
};
