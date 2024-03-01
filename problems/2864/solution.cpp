#include <string>

class Solution {
 public:
  std::string maximumOddBinaryNumber(std::string s) {
    int count = 0;
    for (const auto c : s) {
      if (c == '1') ++count;
    }

    if (count == 0) {
      return s;
    }

    --count;
    s[s.size() - 1] = '1';

    for (std::size_t i = 0; i < s.size() - 1; ++i) {
      if (count > 0) {
        s[i] = '1';
        --count;
      } else {
        s[i] = '0';
      }
    }

    return s;
  }
};
