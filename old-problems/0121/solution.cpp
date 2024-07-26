#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int highestProfit{0};
    int lowestPrice{10001};
    for (const auto price : prices) {
      if (price < lowestPrice) {
        lowestPrice = price;
      } else if (price - lowestPrice > highestProfit) {
        highestProfit = price - lowestPrice;
      }
    }
    return highestProfit;
  }
};
