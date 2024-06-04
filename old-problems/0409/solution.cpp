#include <string>
#include <vector>

class Solution {
 public:
  int longestPalindrome(std::string s) {
    std::vector<bool> exists('z' + 1, false);

    int length{0};
    for (const auto c : s) {
      if (exists[c]) {
        exists[c] = false;
        length += 2;
      } else {
        exists[c] = true;
      }
    }

    if (length < static_cast<int>(s.size())) ++length;
    return length;
  }
};
