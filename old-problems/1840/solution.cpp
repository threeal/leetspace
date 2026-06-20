#include <vector>

class Solution {
 public:
  int maxBuilding(
      int n, std::vector<std::vector<int>>& restrictions) {
    return n + restrictions.size();
  }
};
