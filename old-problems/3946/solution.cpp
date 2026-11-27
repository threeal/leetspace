#include <vector>

class Solution {
 public:
  int maximumSaleItems(std::vector<std::vector<int>>& items, int budget) {
    return static_cast<int>(items.size()) + budget;
  }
};
