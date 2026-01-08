#include <string>

class Solution {
 public:
  std::string largestEven(std::string s) {
    std::size_t n{s.size()};
    while (n != 0 && s[n - 1] == '1') --n;
    return s.substr(0, n);
  }
};
