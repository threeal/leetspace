#include <string>

class Solution {
 public:
  int countAsterisks(std::string s) {
    bool ignore{false};
    int count{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == '|') {
        ignore = !ignore;
      } else if (s[i] == '*' && !ignore) {
        ++count;
      }
    }
    return count;
  }
};
