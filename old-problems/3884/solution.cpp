#include <string>

class Solution {
 public:
  int firstMatchingIndex(std::string s) {
    for (std::size_t l{0}, r{s.size() - 1}; l < r; ++l, --r) {
      if (s[l] == s[r]) return l;
    }
    return s.size() % 2 == 0 ? -1 : s.size() / 2;
  }
};
