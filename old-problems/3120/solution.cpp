#include <bit>
#include <cstdint>
#include <string>

class Solution {
 public:
  int numberOfSpecialChars(std::string word) {
    std::uint32_t lower{0}, upper{0};
    for (char c : word) {
      if (c >= 'a') {
        lower |= 1 << (c - 'a');
      } else {
        upper |= 1 << (c - 'A');
      }
    }
    return std::popcount(lower & upper);
  }
};
