#include <string>

class Solution {
 public:
  std::string toHex(int num) {
    if (num == 0) return "0";

    int n{28};
    while (num >> n == 0) n -= 4;

    std::string hex(1 + n / 4, '0');
    for (int i{0}; i <= n; i += 4) {
      const int val{(num >> i) & 15};
      hex[(n - i) / 4] = val >= 10 ? 'a' + val - 10 : '0' + val;
    }

    return hex;
  }
};
