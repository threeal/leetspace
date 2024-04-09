#include <string>

class Solution {
 public:
  std::string makeGood(std::string s) {
    std::size_t l{0};
    for (std::size_t r{1}; r < s.size(); ++r) {
      if (s[l] < s[r] ? s[l] + 32 == s[r] : s[l] == s[r] + 32) {
        if (l > 0) {
          --l;
        } else if (++r < s.size()) {
          s[l] = s[r];
        } else {
          return "";
        }
      } else {
        s[++l] = s[r];
      }
    }

    s.resize(l + 1);
    return s;
  }
};
