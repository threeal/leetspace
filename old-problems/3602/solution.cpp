#include <algorithm>
#include <string>

class Solution {
 public:
  std::string concatHex36(int n) {
    std::string str{};

    int val{n * n * n};
    while (val > 0) {
      str += val % 36 < 10 ? ('0' + val % 36) : ('A' + val % 36 - 10);
      val /= 36;
    }

    val = n * n;
    while (val > 0) {
      str += val % 16 < 10 ? ('0' + val % 16) : ('A' + val % 16 - 10);
      val /= 16;
    }

    std::reverse(str.begin(), str.end());
    return str;
  }
};
