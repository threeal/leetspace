#include <string>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    std::size_t longest{0};
    bool exists[256]{false};
    for (std::size_t l{0}, r{0}; r < s.size(); ++r) {
      while (exists[s[r]]) {
        exists[s[l]] = false;
        ++l;
      }
      exists[s[r]] = true;
      if (r - l + 1 > longest) longest = r - l + 1;
    }
    return longest;
  }
};
