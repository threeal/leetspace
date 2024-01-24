#include <string>

class Solution {
 public:
  bool isMatch(std::string s, std::string p) {
    if (p.empty()) {
      return s.empty();
    } else if (s.empty()) {
      if (p.size() >= 2 && p[1] == '*') {
        return isMatch(s, p.substr(2));
      } else {
        return false;
      }
    } else if (p.size() >= 2 && p[1] == '*') {
      if (s[0] == p[0] || p[0] == '.') {
        if (isMatch(s.substr(1), p)) {
          return true;
        } else {
          return isMatch(s, p.substr(2));
        }
      } else {
        return isMatch(s, p.substr(2));
      }
    } else if (s[0] == p[0] || p[0] == '.') {
      return isMatch(s.substr(1), p.substr(1));
    } else {
      return false;
    }
  }
};
