#include <vector>

class Solution {
 public:
  std::vector<int> finalPrices(std::vector<int>& prices) {
    for (std::size_t i{0}; i < prices.size(); ++i) {
      for (std::size_t j{i + 1}; j < prices.size(); ++j) {
        if (prices[j] <= prices[i]) {
          prices[i] -= prices[j];
          break;
        }
      }
    }
    return prices;
  }
};
