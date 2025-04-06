#include <string>
#include <utility>

class Solution {
 public:
  std::string countAndSay(int n) {
    std::string str{"1"}, prev{};
    while (--n > 0) {
      std::swap(str, prev);
      str.clear();

      int count{1};
      for (std::size_t i{1}; i <= prev.size(); ++i) {
        if (prev[i] != prev[i - 1]) {
          int exp{1};
          while (exp * 10 <= count) exp *= 10;
          while (exp > 0) {
            str += '0' + count / exp;
            exp /= 10;
          }
          str += prev[i - 1];
          count = 1;
        } else {
          ++count;
        }
      }
    }
    return str;
  }
};
