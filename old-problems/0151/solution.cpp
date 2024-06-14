#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string s) {
    auto right = s.begin();
    auto it = right;

    while (it != s.end() && *it == ' ') ++it;

    while (it != s.end()) {
      const auto left = right;
      while (it != s.end() && *it != ' ') {
        *right = *it;
        ++right;
        ++it;
      }

      std::reverse(left, right);

      while (it != s.end() && *it == ' ') ++it;

      if (it != s.end()) {
        *right = ' ';
        ++right;
      }
    }

    s.resize(std::distance(s.begin(), right));

    std::reverse(s.begin(), s.end());

    return s;
  }
};
