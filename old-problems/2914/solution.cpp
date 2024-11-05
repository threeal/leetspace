#include <string>

class Solution {
 public:
  int minChanges(std::string s) {
    int changes{0};
    for (std::size_t i{0}; i < s.size(); i += 2) {
      if (s[i] != s[i + 1]) ++changes;
    }
    return changes;
  }
};
