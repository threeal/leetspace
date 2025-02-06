#include <string>

class Solution {
 public:
  bool isNumber(std::string s) {
    std::size_t i{0};
    if (s[i] == '+' || s[i] == '-') ++i;
    if (i < s.size()) {
      if (s[i] == '.') {
        ++i;
        if (s[i] >= '0' && s[i] <= '9') {
          ++i;
          while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
          if (i >= s.size()) return true;

          if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            if (s[i] == '+' || s[i] == '-') ++i;
            if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
              ++i;
              while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
              if (i >= s.size()) return true;
            }
          }
        }
      } else if (s[i] >= '0' && s[i] <= '9') {
        ++i;
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
        if (i >= s.size()) return true;

        if (s[i] == '.') {
          ++i;
          if (i >= s.size()) return true;

          if (s[i] >= '0' && s[i] <= '9') {
            ++i;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
            if (i >= s.size()) return true;

            if (s[i] == 'e' || s[i] == 'E') {
              ++i;
              if (s[i] == '+' || s[i] == '-') ++i;
              if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                ++i;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
                if (i >= s.size()) return true;
              }
            }
          } else if (s[i] == 'e' || s[i] == 'E') {
            ++i;
            if (s[i] == '+' || s[i] == '-') ++i;
            if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
              ++i;
              while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
              if (i >= s.size()) return true;
            }
          }
        } else if (s[i] == 'e' || s[i] == 'E') {
          ++i;
          if (s[i] == '+' || s[i] == '-') ++i;
          if (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            ++i;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') ++i;
            if (i >= s.size()) return true;
          }
        }
      }
    }
    return false;
  }
};
