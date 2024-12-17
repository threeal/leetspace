#include <string>
#include <vector>

class Solution {
 public:
  std::string addSpaces(std::string s, std::vector<int>& spaces) {
    int l = s.size() - 1;
    int i = spaces.size() - 1;

    s.resize(s.size() + spaces.size(), ' ');
    int r = s.size() - 1;

    while (l >= 0) {
      if (l == spaces[i] - 1) {
        if (--i < 0) break;
      } else {
        s[r] = s[l];
        s[l] = ' ';
        --l;
      }
      --r;
    }

    return s;
  }
};
