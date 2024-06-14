#include <cstdlib>
#include <string>

class Solution {
 public:
  int equalSubstring(std::string s, std::string t, int maxCost) {
    int maxLength{0};
    int left = s.size() - 1;
    int right = s.size() - 1;
    while (left >= 0) {
      maxCost -= std::abs(s[left] - t[left]);
      while (maxCost < 0) {
        maxCost += std::abs(s[right] - t[right]);
        --right;
      }
      if (right - left + 1 > maxLength) maxLength = right - left + 1;
      --left;
    }
    return maxLength;
  }
};
