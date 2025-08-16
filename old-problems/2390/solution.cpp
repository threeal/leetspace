#include <string>

class Solution {
 public:
  std::string removeStars(std::string s) {
    std::size_t n{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == '*') {
        --n;
      } else {
        s[n++] = s[i];
      }
    }
    s.resize(n);
    return s;
  }
};
