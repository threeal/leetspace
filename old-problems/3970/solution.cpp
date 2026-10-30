#include <string>
#include <vector>

class Solution {
 public:
  int shortestPath(int n, std::vector<std::vector<int>>& edges, std::string labels, int k) {
    return n + static_cast<int>(edges.size() + labels.size()) + k;
  }
};
