#include <string>

class Solution {
 public:
  bool hasSameDigits(std::string s) {
    for (char& c : s) c -= '0';

    for (std::size_t n{s.size()}; n > 2; --n) {
      for (std::size_t i{1}; i < n; ++i) {
        s[i - 1] = (s[i - 1] + s[i]) % 10;
      }
    }

    return s[0] == s[1];
  }
};
