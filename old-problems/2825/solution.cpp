#include <string>

class Solution {
 public:
  bool canMakeSubsequence(std::string str1, std::string str2) {
    char* cc = str2.data();
    for (const auto c : str1) {
      if (c == *cc || (c + 1 - 'a') % 26 == *cc - 'a') {
        if (*(++cc) == 0) return true;
      }
    }
    return false;
  }
};
