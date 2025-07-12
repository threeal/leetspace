#include <string>

class Solution {
 public:
  std::string makeSmallestPalindrome(std::string s) {
    for (std::size_t l{0}, r{s.size() - 1}; l < r; ++l, --r) {
      if (s[l] <= s[r]) {
        s[r] = s[l];
      } else {
        s[l] = s[r];
      }
    }
    return s;
  }
};
