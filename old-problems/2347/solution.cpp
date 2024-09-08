#include <string>
#include <vector>

class Solution {
 public:
  std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits) {
    for (int i{4}; i > 0; --i) {
      if (suits[i] != suits[0]) {
        int maxPair{0};
        for (int i{4}; i >= 0; --i) {
          int pair{0};
          for (int j{4}; j >= 0; --j) {
            if (ranks[i] == ranks[j]) ++pair;
          }
          if (pair > maxPair) maxPair = pair;
        }
        return maxPair < 3
            ? (maxPair < 2 ? "High Card" : "Pair")
            : "Three of a Kind";
      }
    }
    return "Flush";
  }
};
