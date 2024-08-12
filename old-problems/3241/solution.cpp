#include <vector>

class Solution {
 public:
  std::vector<int> timeTaken(std::vector<std::vector<int>>& edges) {
    return std::vector<int>(edges.size() + 1, 0);
  }
};
