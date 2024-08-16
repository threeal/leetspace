#include <string>

class Solution {
 public:
  int secondsToRemoveOccurrences(std::string s) {
    auto c = s.data();
    while (*c == '1') ++c;

    int maxSeconds{0};
    int zeros{0};
    int consecutiveOnes{0};
    while (*c != 0) {
      if (*c == '1') {
        if (zeros + consecutiveOnes >= maxSeconds) {
          maxSeconds = zeros + consecutiveOnes;
        }
        ++consecutiveOnes;
      } else {
        ++zeros;
        if (consecutiveOnes > 0) --consecutiveOnes;
      }
      ++c;
    }
    return maxSeconds;
  }
};
