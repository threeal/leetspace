#include <vector>

class Solution {
 public:
  long long maximumProfit(std::vector<int>& prices, int k) {
    return prices.size() + k;
  }
};
