#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseStr(std::string s, int k) {
    for (std::size_t i{0}; i < s.size(); i += k + k) {
      std::reverse(s.begin() + i, s.begin() + std::min(s.size(), i + k));
    }
    return s;
  }
};
