#include <string>

class Solution {
 public:
  int minLengthAfterRemovals(std::string s) {
    std::size_t a{0};
    for (char c : s) {
      if (c == 'a') ++a;
    }
    a *= 2;
    return a >= s.size() ? a - s.size() : s.size() - a;
  }
};
