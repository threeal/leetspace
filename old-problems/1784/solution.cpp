#include <string>

class Solution {
 public:
  bool checkOnesSegment(std::string s) {
    std::size_t i{0};
    while (i < s.size() && s[i] == '1') ++i;
    while (i < s.size() && s[i] == '0') ++i;
    return i == s.size();
  }
};
