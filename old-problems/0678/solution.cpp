#include <string>
#include <string_view>

class Solution {
 public:
  bool checkValidString(std::string s) {
    int minLevel{0};
    int maxLevel{0};

    for (const auto c : s) {
      switch (c) {
        case '(':
          ++minLevel;
          ++maxLevel;
          break;

        case ')':
          --minLevel;
          --maxLevel;
          break;

        case '*':
          --minLevel;
          ++maxLevel;
          break;
      }

      if (maxLevel < 0) return false;
      if (minLevel < 0) minLevel = 0;
    }

    return minLevel == 0;
  }
};
