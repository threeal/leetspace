#include <string>

class Solution {
 public:
  std::string removeKdigits(std::string num, int k) {
    std::size_t n{0}, i{0};
    while (i < num.size() && k > 0) {
      while (k > 0 && n > 0 && num[n - 1] > num[i]) {
        --n;
        --k;
      }
      if (n == 0 && num[i] == '0') {
        ++i;
      } else {
        num[n++] = num[i++];
      }
    }

    while (k > 0 && n > 0) {
      --n;
      --k;
    };

    while (i < num.size()) {
      if (n == 0 && num[i] == '0') {
        ++i;
      } else {
        num[n++] = num[i++];
      }
    }

    if (n == 0) return "0";

    num.resize(n);
    return num;
  }
};
