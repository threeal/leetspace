#include <vector>

class Solution {
 public:
  int minCost(int n, std::vector<int>& cuts) {
    return n * cuts.size();
  }
};
