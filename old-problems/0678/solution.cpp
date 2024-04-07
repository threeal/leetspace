#include <string>
#include <string_view>

class Solution {
 public:
  bool checkValidString(std::string s) {
    return iterateIfStringValid(s, 0);
  }

 public:
  bool iterateIfStringValid(std::string_view v, int level) {
    if (v.empty()) return level == 0;

    switch (v[0]) {
      case '(':
        return iterateIfStringValid(v.substr(1), level + 1);

      case ')':
        if (level < 1) return false;
        return iterateIfStringValid(v.substr(1), level - 1);

      case '*':
        const bool res = iterateIfStringValid(v.substr(1), level) || iterateIfStringValid(v.substr(1), level + 1);
        return (!res && level > 0) ? iterateIfStringValid(v.substr(1), level - 1) : res;
    }

    return false;
  }
};
