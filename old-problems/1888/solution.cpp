#include <algorithm>
#include <string>

class Solution {
 public:
  int minFlips(std::string s) {
    int zeroDiff{0}, oneDiff{0};
    for (std::size_t i{0}; i < s.size(); ++i) {
      if (s[i] == '0') {
        ++oneDiff;
      } else {
        ++zeroDiff;
      }

      if (++i >= s.size()) break;

      if (s[i] == '1') {
        ++oneDiff;
      } else {
        ++zeroDiff;
      }
    }

    int minDiff = std::min(zeroDiff, oneDiff);
    if (s.size() % 2 != 0) {
      for (std::size_t i{s.size() - 1}; i > 0; --i) {
        std::swap(zeroDiff, oneDiff);
        if (s[i] == '1') {
          ++zeroDiff;
          --oneDiff;
          if (oneDiff < minDiff) minDiff = oneDiff;
        } else {
          --zeroDiff;
          ++oneDiff;
          if (zeroDiff < minDiff) minDiff = zeroDiff;
        }
      }
    }

    return minDiff;
  }
};
