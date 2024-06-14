#include <string>

class Solution {
 public:
  bool checkString(std::string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == 'b') --i;
    while (i >= 0 && s[i] == 'a') --i;
    return i < 0;
  }
};
