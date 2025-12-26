#include <vector>

class Solution {
 public:
  long long minCost(
      std::vector<int>& basket1, std::vector<int>& basket2) {
    return basket1.front() + basket2.front();
  }
};
