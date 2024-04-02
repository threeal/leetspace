#include <string>

class Solution {
 public:
  int lengthOfLastWord(std::string s) {
    const int n = s.size();
    int b = n - 1;
    while (b >= 0) {
      if (s[b] != ' ') break;
      b--;
    }
    int a = b;
    while (a >= 0) {
      if (s[a] == ' ') break;
      a--;
    }
    return b - a;
  }
};
