#include <algorithm>
#include <string>

class Solution {
 public:
  int maxScore(std::string s) {
    int zeros = s[0] == '0' ? 1 : 0;

    int ones = 0;
    for (std::size_t i = 1; i < s.size(); ++i) {
      if (s[i] == '1') ++ones;
    }

    int score = zeros + ones;
    for (std::size_t i = 1; i < s.size() - 1; ++i) {
      switch (s[i]) {
        case '0':
          ++zeros;
          break;

        case '1':
          --ones;
          break;
      }
      score = std::max(score, zeros + ones);
    }

    return score;
  }
};
