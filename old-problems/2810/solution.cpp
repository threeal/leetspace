#include <algorithm>
#include <string>

class Solution {
 public:
  std::string finalString(std::string s) {
    std::size_t out{0};
    for (std::size_t i = 0; i < s.size(); ++i) {
      if (s[i] == 'i') {
        std::reverse(s.begin(), s.begin() + out);
      } else {
        s[out] = s[i];
        ++out;
      }
    }
    return s.substr(0, out);
  }
};
