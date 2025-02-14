#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int totalProfit{0};
    for (std::size_t i{1}; i < prices.size(); ++i) {
      totalProfit += std::max(0, prices[i] - prices[i - 1]);
    }
    return totalProfit;
  }
};
