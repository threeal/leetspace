#include <string>

class Solution {
 public:
  int maxConsecutiveAnswers(std::string answerKey, int k) {
    std::size_t maxConsecutive{0};
    std::size_t lt{0}, lf{0};
    int kt{k}, kf{k};
    for (std::size_t r{0}; r < answerKey.size(); ++r) {
      if (answerKey[r] == 'F') {
        --kt;
        while (kt < 0) {
          if (answerKey[lt] == 'F') ++kt;
          ++lt;
        }
      } else {
        --kf;
        while (kf < 0) {
          if (answerKey[lf] == 'T') ++kf;
          ++lf;
        }
      }

      const std::size_t consecutive{r - (lt <= lf ? lt : lf) + 1};
      if (consecutive > maxConsecutive) maxConsecutive = consecutive;
    }
    return maxConsecutive;
  }
};
