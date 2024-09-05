#include <vector>

class Solution {
 public:
  int countPaths(int n, std::vector<std::vector<int>>& roads) {
    return n * roads.size();
  }
};
