#include <algorithm>
#include <string>

class Solution {
 public:
  std::string smallestPalindrome(std::string s) {
    std::sort(s.begin(), s.begin() + s.size() / 2);
    for (std::size_t i{s.size() / 2}; i < s.size(); ++i) {
      s[i] = s[s.size() - i - 1];
    }
    return s;
  }
};
