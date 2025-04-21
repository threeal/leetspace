#include <vector>

class Solution {
 public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    return flowerbed.empty() || n == 0;
  }
};
