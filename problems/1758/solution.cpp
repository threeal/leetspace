#include <algorithm>
#include <string>

class Solution {
 public:
  int minOperations(std::string s) {
    int zeroFirst = 0;
    int oneFirst = 0;

    for (std::size_t i = 0; i < s.size(); ++i) {
      if (i % 2 == 0) {
        if (s[i] == '0') {
          ++oneFirst;
        } else {
          ++zeroFirst;
        }
      } else {
        if (s[i] == '0') {
          ++zeroFirst;
        } else {
          ++oneFirst;
        }
      }
    }

    return std::min(zeroFirst, oneFirst);
  }
};
