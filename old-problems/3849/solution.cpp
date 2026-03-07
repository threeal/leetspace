#include <string>

class Solution {
 public:
  std::string maximumXor(std::string s, std::string t) {
    std::size_t zeros{0};
    for (char c : t) {
      if (c == '0') ++zeros;
    }

    if (zeros < s.size()) {
      for (std::size_t i{0}; i < zeros; ++i) {
        if (s[i] == '0') {
          s[i] = '1';
          if (++zeros == s.size()) return s;
        }
      }

      for (std::size_t i{zeros}; i < s.size(); ++i) {
        s[i] = s[i] == '0' ? '1' : '0';
      }
    }

    return s;
  }
};
