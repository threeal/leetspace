#include <vector>

class Solution {
 public:
  int maxIceCream(std::vector<int>& costs, int coins) {
    std::sort(costs.begin(), costs.end());

    int count{0};
    for (const int cost : costs) {
      coins -= cost;
      if (coins >= 0) {
        ++count;
      } else {
        break;
      }
    }

    return count;
  }
};
