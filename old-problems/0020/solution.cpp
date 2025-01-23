#include <string>

class Solution {
 public:
  bool isValid(std::string s) {
    std::size_t i{0};
    for (const auto c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          s[i] = c;
          ++i;
          break;

        case ')':
          if (i == 0 || s[i - 1] != '(') return false;
          --i;
          break;

        case ']':
          if (i == 0 || s[i - 1] != '[') return false;
          --i;
          break;

        case '}':
          if (i == 0 || s[i - 1] != '{') return false;
          --i;
          break;
      }
    }
    return i == 0;
  }
};
