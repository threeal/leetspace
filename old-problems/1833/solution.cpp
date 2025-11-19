#include <vector>

class Solution {
 public:
  int maxIceCream(std::vector<int>& costs, int coins) {
    return costs.size() + coins;
  }
};
