#include <string>

class Solution {
 public:
  bool isAdjacentDiffAtMostTwo(std::string s) {
    for (std::size_t i{1}; i < s.size(); ++i) {
      if (s[i] > s[i - 1]) {
        if (s[i] - s[i - 1] > 2) return false;
      } else if (s[i - 1] - s[i] > 2) {
        return false;
      }
    }
    return true;
  }
};
