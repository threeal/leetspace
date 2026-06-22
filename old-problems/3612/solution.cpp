#include <algorithm>
#include <string>

class Solution {
 public:
  std::string processStr(std::string s) {
    std::string res{};
    for (char c : s) {
      switch (c) {
        case '*':
          if (!res.empty()) res.pop_back();
          break;

        case '#':
          res += res;
          break;

        case '%':
          if (!res.empty()) std::reverse(res.begin(), res.end());
          break;

        default:
          res += c;
      }
    }
    return res;
  }
};
