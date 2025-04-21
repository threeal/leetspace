#include <string>

class Solution {
 public:
  bool repeatedSubstringPattern(std::string s) {
    for (std::size_t n{1}; n * 2 <= s.size(); ++n) {
      if (s.size() % n != 0) continue;

      bool valid{true};
      for (std::size_t i{n}; i < s.size(); i += n) {
        for (std::size_t j{0}; j < n; ++j) {
          if (s[i + j] != s[j]) {
            valid = false;
            i = s.size();
            j = n;
          }
        }
      }

      if (valid) return true;
    }

    return false;
  }
};
