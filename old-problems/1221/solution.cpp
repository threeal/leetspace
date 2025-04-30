#include <string>

class Solution {
 public:
  int balancedStringSplit(std::string s) {
    int count{0}, balance{0};
    for (const char c : s) {
      if (c == 'L') {
        if (++balance == 0) ++count;
      } else {
        if (--balance == 0) ++count;
      }
    }
    return count;
  }
};
