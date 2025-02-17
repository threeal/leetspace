#include <string>

class Solution {
 public:
  std::string clearDigits(std::string s) {
    std::size_t n{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        --n;
      } else {
        s[n] = s[i];
        ++n;
      }
    }
    s.resize(n);
    return s;
  }
};
