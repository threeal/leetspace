#include <string>

class Solution {
 public:
  bool digitCount(std::string num) {
    char freqs[10]{0};
    for (const char digit : num) ++freqs[digit - '0'];
    for (std::size_t i{0}; i < num.size(); ++i) {
      if (num[i] - '0' != freqs[i]) return false;
    }
    return true;
  }
};
