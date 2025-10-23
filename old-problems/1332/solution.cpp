#include <string>

class Solution {
 public:
  int removePalindromeSub(std::string s) {
    for (std::size_t l{0}, r{s.size() - 1}; l < r; ++l, --r) {
      if (s[l] != s[r]) return 2;
    }
    return 1;
  }
};
