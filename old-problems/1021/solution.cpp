#include <string>

class Solution {
 public:
  std::string removeOuterParentheses(std::string s) {
    int level{0};
    std::size_t n{0};
    for (const char c : s) {
      if (c == '(') {
        if (++level != 1) s[n++] = c;
      } else {
        if (--level != 0) s[n++] = c;
      }
    }
    s.resize(n);
    return s;
  }
};
