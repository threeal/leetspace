#include <vector>

class Solution {
 public:
  int numOfUnplacedFruits(std::vector<int>& fruits, std::vector<int>& baskets) {
    return fruits[0] + baskets[0];
  }
};
