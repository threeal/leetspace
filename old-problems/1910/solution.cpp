#include <string>

class Solution {
 public:
  std::string removeOccurrences(std::string s, std::string part) {
    if (s.size() < part.size()) return s;

    std::size_t n{part.size() - 1};
    for (std::size_t i{n}; i < s.size(); ++i) {
      s[n] = s[i];
      ++n;
      if (n >= part.size() &&
          s.compare(n - part.size(), part.size(), part) == 0) {
        n -= part.size();
      }
    }

    s.resize(n);
    return s;
  }
};
