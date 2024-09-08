#include <string>
#include <vector>

class Solution {
 public:
  std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits) {
    for (int i{4}; i > 0; --i) {
      if (suits[i] != suits[0]) {
        int ones{0}, twos{0};
        for (const auto rank : ranks) {
          if ((ones & (1 << rank)) > 0) {
            if ((twos & (1 << rank)) > 0) {
              return "Three of a Kind";
            } else {
              twos |= 1 << rank;
            }
          } else {
            ones |= 1 << rank;
          }
        }
        return twos > 0 ? "Pair" : "High Card";
      }
    }
    return "Flush";
  }
};
