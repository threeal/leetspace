#include <string>

class Solution {
 public:
  int countKeyChanges(std::string s) {
    int changes{0};
    if (s[0] > 'Z') s[0] += 'A' - 'a';
    for (std::size_t i{1}; i < s.size(); ++i) {
      if (s[i] > 'Z') s[i] += 'A' - 'a';
      if (s[i] != s[i - 1]) ++changes;
    }
    return changes;
  }
};
