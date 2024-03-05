#include <string>

class Solution {
 public:
  int minimumLength(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
      if (s[left] != s[right]) break;

      const auto c = s[left];
      while (s[left] == c && left <= right) ++left;
      while (s[right] == c && left <= right) --right;
    }

    return right - left + 1;
  }
};
