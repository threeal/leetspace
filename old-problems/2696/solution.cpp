#include <string>

class Solution {
 public:
  int minLength(std::string s) {
    int i{-1};
    for (const auto c : s) {
      if (i >= 0 && ((s[i] == 'A' && c == 'B') || (s[i] == 'C' && c == 'D'))) {
        --i;
      } else {
        s[++i] = c;
      }
    }
    return i + 1;
  }
};
