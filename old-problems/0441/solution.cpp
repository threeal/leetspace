#include <cstdint>

class Solution {
 public:
  int arrangeCoins(int n) {
    std::uint_fast32_t low{1};
    std::uint_fast32_t high{92681};

    while (low < high) {
      const std::uint_fast32_t mid{(low + high + 1) / 2};
      if ((mid + mid * mid) / 2 > static_cast<std::uint_fast32_t>(n)) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    return low;
  }
};
