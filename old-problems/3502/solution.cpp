#include <vector>

class Solution {
 public:
  std::vector<int> minCosts(std::vector<int>& cost) {
    int min{cost[0]};
    for (std::size_t i{1}; i < cost.size(); ++i) {
      if (min < cost[i]) {
        cost[i] = min;
      } else {
        min = cost[i];
      }
    }
    return cost;
  }
};
