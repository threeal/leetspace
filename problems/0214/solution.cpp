#include <algorithm>
#include <string>

class Solution {
 public:
  std::string shortestPalindrome(std::string s) {
    std::size_t i{0};
    for (int j = s.size() - 1; j >= 0; --j) {
      if (s[i] == s[j]) ++i;
    }
    if (i == s.size()) return s;
    auto rev = s.substr(i);
    std::reverse(rev.begin(), rev.end());
    return rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
  }
};
