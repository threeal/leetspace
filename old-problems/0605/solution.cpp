#include <vector>

class Solution {
 public:
  bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    std::size_t i{0};
    while (i < flowerbed.size() && flowerbed[i] == 0) ++i;
    if (i == flowerbed.size()) {
      n -= (i + 1) / 2;
      return n <= 0;
    };

    n -= i / 2;
    if (n <= 0) return true;

    int zeros{0};
    while (i < flowerbed.size()) {
      if (flowerbed[i] == 0) {
        ++zeros;
      } else {
        if (zeros > 2) {
          n -= (zeros - 1) / 2;
          if (n <= 0) return true;
        }
        zeros = 0;
      }
      ++i;
    }

    n -= zeros / 2;
    return n <= 0;
  }
};
