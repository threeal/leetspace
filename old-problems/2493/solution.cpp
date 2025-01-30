#include <vector>

class Solution {
 public:
  int magnificentSets(int n, std::vector<std::vector<int>>& edges) {
    return n * edges.size();
  }
};
