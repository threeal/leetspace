#include <string>

class Solution {
 public:
  int countSubstrings(std::string s, std::string t) {
    int count{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      for (std::size_t j{0}; j < t.size(); ++j) {
        std::size_t ii{i}, jj{j};
        while (ii < s.size() && jj < t.size() && s[ii] == t[jj]) ++ii, ++jj;
        if (ii < s.size() && jj < t.size()) {
          ++count, ++ii, ++jj;
          while (ii < s.size() && jj < t.size() && s[ii] == t[jj]) {
            ++count, ++ii, ++jj;
          }
        }
      }
    }
    return count;
  }
};
