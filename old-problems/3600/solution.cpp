#include <vector>

class Solution {
 public:
  int maxStability(int n, std::vector<std::vector<int>>& edges, int k) {
    return n + edges.size() + k;
  }
};
