#include <vector>

class Solution {
 public:
  int maxNumEdgesToRemove(int n, std::vector<std::vector<int>>& edges) {
    return edges.size() - n;
  }
};
