#include <string>

class Solution {
 public:
  int countSegments(std::string s) {
    int count{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      while (i < s.size() && s[i] == ' ') ++i;
      if (i < s.size()) {
        ++count;
        while (i < s.size() && s[i] != ' ') ++i;
      }
    }
    return count;
  }
};
