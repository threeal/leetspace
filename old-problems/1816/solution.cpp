#include <string>

class Solution {
 public:
  std::string truncateSentence(std::string s, int k) {
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == ' ' && --k == 0) {
        s.resize(i);
        break;
      }
    }
    return s;
  }
};
