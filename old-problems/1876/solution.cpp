#include <string>

class Solution {
 public:
  int countGoodSubstrings(std::string s) {
    int count{0};
    for (int i = s.size() - 3; i >= 0; --i) {
      if (s[i] == s[i + 1]) continue;
      if (s[i] == s[i + 2]) continue;
      if (s[i + 1] == s[i + 2]) continue;
      ++count;
    }
    return count;
  }
};
