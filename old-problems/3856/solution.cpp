#include <string>

class Solution {
 public:
  std::string trimTrailingVowels(std::string s) {
    bool done{false};
    std::size_t n{s.size()};
    while (!done) {
      switch (s[n - 1]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          if (--n == 0) {
            done = true;
          }
          break;

        default:
          done = true;
      }
    }
    s.resize(n);
    return s;
  }
};
