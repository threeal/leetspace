#include <string>

class Solution {
 public:
  std::string maxSumOfSquares(int num, int sum) {
    if (num * 9 < sum) return "";
    std::string str(num, '0');
    std::size_t i{0};
    while (sum > 9) {
      str[i++] = '9';
      sum -= 9;
    }
    str[i] += sum;
    return str;
  }
};
