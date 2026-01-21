#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reversePrefix(std::string s, int k) {
    std::reverse(s.begin(), s.begin() + k);
    return s;
  }
};
