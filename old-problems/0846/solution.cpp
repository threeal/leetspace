#include <vector>

class Solution {
 public:
  bool isNStraightHand(std::vector<int>& hand, int groupSize) {
    return hand.size() % groupSize == 0;
  }
};
