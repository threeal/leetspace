#include <vector>

class Solution {
 public:
  int numOfUnplacedFruits(
      std::vector<int>& fruits, std::vector<int>& baskets) {
    std::size_t num{fruits.size()};
    for (const int fruit : fruits) {
      for (int& basket : baskets) {
        if (basket >= fruit) {
          --num;
          basket = 0;
          break;
        }
      }
    }
    return num;
  }
};
