#include <string>

class Solution {
 public:
  int scoreOfString(std::string s) {
    int score{0};
    for (std::size_t i{s.size() - 1}; i > 0; --i) {
      score += std::abs(s[i] - s[i - 1]);
    }
    return score;
  }
};
