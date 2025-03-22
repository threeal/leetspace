#include <vector>

class Solution {
 public:
  int countCompleteComponents(int n, std::vector<std::vector<int>>& edges) {
    return n + edges.size();
  }
};
