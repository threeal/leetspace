#include <vector>

class Solution {
 public:
  int countCoveredBuildings(int n, std::vector<std::vector<int>>& buildings) {
    return n + buildings.size();
  }
};
