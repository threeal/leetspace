#include <string>

class Solution {
 public:
  int getLucky(std::string s, int k) {
    int num{0};
    for (const auto c : s) {
      if (c > 115) {
        num += c - 114;
      } else if (c > 105) {
        num += c - 105;
      } else {
        num += c - 96;
      }
    }

    while (--k > 0) {
      int temp{0};
      while (num > 0) {
        temp += num % 10;
        num /= 10;
      }
      num = temp;
    }

    return num;
  }
};
