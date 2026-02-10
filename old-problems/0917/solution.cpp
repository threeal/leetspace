#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseOnlyLetters(std::string s) {
    std::size_t l{0}, r{s.size() - 1};
    while (l < r) {
      while (l < r && !isLetter(s[l])) ++l;
      if (l >= r) break;

      while (l < r && !isLetter(s[r])) --r;
      if (l >= r) break;

      std::swap(s[l], s[r]);
      ++l, --r;
    }
    return s;
  }

 private:
  static bool isLetter(char c) {
    if (c < 'A') return false;
    if (c <= 'Z') return true;
    if (c < 'a') return false;
    if (c <= 'z') return true;
    return false;
  }
};
