#include <limits>
#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices, int fee) {
    int buy{std::numeric_limits<int>::min()}, sell{0};
    for (int price : prices) {
      if (sell - price > buy) buy = sell - price;
      if (buy + price - fee > sell) sell = buy + price - fee;
    }
    return sell;
  }
};
