#include <string>

class Solution {
 public:
  int countSubstrings(std::string s) {
    const int n = s.size();

    int count = 0;
    for (int i = 0; i < n; ++i) {
      int len = 1;
      while (i - len >= 0 && i + len < n) {
        if (s[i - len] != s[i + len]) break;
        ++len;
      }
      count += len;

      len = 0;
      while (i - 1 - len >= 0 && i + len < n) {
        if (s[i - 1 - len] != s[i + len]) break;
        ++len;
      }
      count += len;
    }

    return count;
  }
};
