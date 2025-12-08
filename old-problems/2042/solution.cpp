#include <string>

class Solution {
 public:
  bool areNumbersAscending(std::string s) {
    int prev{-1};
    for (std::size_t i{0}; i < s.size(); ++i) {
      int num{0};
      while (i < s.size() && s[i] != ' ') {
        if (num != -1 && s[i] <= '9') {
          num = num * 10 + s[i] - '0';
        } else {
          num = -1;
        }
        ++i;
      }

      if (num == -1) continue;
      if (num > prev) {
        prev = num;
      } else {
        return false;
      }
    }
    return true;
  }
};
