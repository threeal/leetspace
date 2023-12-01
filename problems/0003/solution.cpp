#include <string>
#include <unordered_set>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    return longest(s.c_str(), s.size());
  }

  int longest(const char* str, int n) {
    std::unordered_set<char> cs;
    int i = 0;
    while (i < n) {
      if (cs.contains(str[i])) break;
      cs.insert(str[i]);
      ++i;
    }
    if (n <= 1) return i;
    auto j = longest(str + 1, n - 1);

    return std::max(i, j);
  }
};
