#include <string>

class Solution {
 public:
  int minAddToMakeValid(std::string s) {
    int added{0};
    int level{0};
    for (const auto c : s) {
      if (c == '(') {
        ++level;
      } else {
        if (level == 0) {
          ++added;
        } else {
          --level;
        }
      }
    }
    return level + added;
  }
};
