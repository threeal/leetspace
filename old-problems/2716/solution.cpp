#include <string>
#include <vector>

class Solution {
 public:
  int minimizedStringLength(std::string s) {
    std::vector<bool> exists(26, false);
    int unique{0};
    for (const char c : s) {
      if (!exists[c - 'a']) {
        exists[c - 'a'] = true;
        ++unique;
      }
    }
    return unique;
  }
};
