#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    return amount / coins.size();
  }
};
