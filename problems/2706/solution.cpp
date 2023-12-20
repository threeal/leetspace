#include <vector>

class Solution {
 public:
  int buyChoco(std::vector<int>& prices, int money) {
    int a = prices[0] < prices[1] ? prices[0] : prices[1];
    int b = prices[0] < prices[1] ? prices[1] : prices[0];

    for (std::size_t i = 2; i < prices.size(); ++i) {
      if (prices[i] >= b) continue;
      if (prices[i] < a) {
        b = a;
        a = prices[i];
      } else {
        b = prices[i];
      }
    }

    return a + b > money ? money : money - a - b;
  }
};
