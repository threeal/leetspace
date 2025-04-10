#include <algorithm>
#include <string>

class Solution {
 public:
  std::string convertToBase7(int num) {
    if (num == 0) return "0";

    const bool neg{num < 0};
    if (neg) num = -num;

    std::string out{};
    while (num > 0) {
      out += '0' + num % 7;
      num /= 7;
    }

    if (neg) out += "-";
    std::reverse(out.begin(), out.end());
    return out;
  }
};
