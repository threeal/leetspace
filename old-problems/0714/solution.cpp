#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices, int fee) {
    return prices.size() + fee;
  }
};
