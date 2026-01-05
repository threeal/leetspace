#include <bit>
#include <string>

class Solution {
 public:
  int maxDistinct(std::string s) {
    unsigned int flag{0};
    for (char c : s) {
      flag |= 1 << (c - 'a');
    }
    return std::popcount(flag);
  }
};
