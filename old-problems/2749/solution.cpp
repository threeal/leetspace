#include <bit>
#include <cstdint>

class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    std::int64_t target{num1};
    target -= num2;
    for (int n{1}; target >= n; ++n) {
      if (std::popcount(static_cast<std::uint64_t>(target)) <= n) return n;
      target -= num2;
    }
    return -1;
  }
};
