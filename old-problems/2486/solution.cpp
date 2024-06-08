#include <string>

class Solution {
 public:
  int appendCharacters(std::string s, std::string t) {
    std::size_t ti{0};
    for (std::size_t si{0}; si < s.size(); ++si) {
      if (s[si] == t[ti]) ++ti;
    }
    return t.size() - ti;
  }
};
