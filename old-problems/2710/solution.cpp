#include <string>

class Solution {
 public:
  std::string removeTrailingZeros(std::string num) {
    int n = num.size() - 1;
    while (n >= 0 && num[n] == '0') --n;
    num.resize(n + 1);
    return num;
  }
};
