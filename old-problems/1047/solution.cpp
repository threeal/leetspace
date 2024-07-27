#include <string>

class Solution {
 public:
  std::string removeDuplicates(std::string s) {
    std::size_t out{1};
    for (std::size_t i{1}; i < s.size(); ++i) {
      while (out > 0 && i < s.size() && s[out - 1] == s[i]) {
        --out;
        ++i;
      }
      if (i < s.size()) {
        s[out] = s[i];
        ++out;
      }
    }
    return s.substr(0, out);
  }
};
