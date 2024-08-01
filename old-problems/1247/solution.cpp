#include <string>

class Solution {
 public:
  int minimumSwap(std::string s1, std::string s2) {
    int x1{0}, y1{0};
    for (int i = s1.size() - 1; i >= 0; --i) {
      if (s1[i] != s2[i]) {
        if (s1[i] == 'x') {
          ++x1;
        } else {
          ++y1;
        }
      }
    }

    return x1 % 2 == 0
        ? (y1 % 2 == 0 ? (x1 + y1) / 2 : -1)
        : (y1 % 2 == 0 ? -1 : (x1 + y1) / 2 + 1);
  }
};
