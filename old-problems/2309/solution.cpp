#include <cstdint>
#include <string>

class Solution {
 public:
  std::string greatestLetter(std::string s) {
    std::uint32_t upper{0}, lower{0};
    for (char c : s) {
      if (c >= 'a') {
        lower |= 1 << (c - 'a');
      } else {
        upper |= 1 << (c - 'A');
      }
    }

    upper &= lower;
    if (upper == 0) return "";

    s = "A";
    s[0] += 31 - std::countl_zero(upper);

    return s;
  }
};
