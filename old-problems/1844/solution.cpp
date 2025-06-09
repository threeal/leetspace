#include <string>

class Solution {
 public:
  std::string replaceDigits(std::string s) {
    for (std::size_t i{1}; i < s.size(); i += 2) {
      s[i] += s[i - 1] - '0';
    }
    return s;
  }
};
