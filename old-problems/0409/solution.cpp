#include <bit>
#include <cstdint>
#include <string>

class Solution {
 public:
  int longestPalindrome(std::string s) {
    std::uint32_t lower{0};
    std::uint32_t upper{0};

    for (const auto c : s) {
      if (c >= 'a') {
        lower ^= 1 << (c - 'a');
      } else {
        upper ^= 1 << (c - 'A');
      }
    }

    return s.size() - std::max(0, std::popcount(lower) + std::popcount(upper) - 1);
  }
};
