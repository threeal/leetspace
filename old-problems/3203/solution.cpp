#include <vector>

class Solution {
 public:
  int minimumDiameterAfterMerge(
      std::vector<std::vector<int>>& edges1, std::vector<std::vector<int>>& edges2) {
    return edges1.size() + edges2.size();
  }
};
