#include <algorithm>
#include <vector>

class Solution {
 public:
  bool isNStraightHand(std::vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;

    std::sort(hand.begin(), hand.end());

    for (std::size_t i{0}; i < hand.size(); i += groupSize) {
      auto begin = hand.begin() + i;
      int val{*begin + 1};
      *begin = -1;

      auto it = begin + 1;
      for (int i{groupSize - 1}; i > 0; --i) {
        it = std::lower_bound(it, hand.end(), val);
        if (it == hand.end() || *it != val) return false;
        *it = -1;
        ++it;
        ++val;
      }

      std::sort(begin, it);
    }

    return true;
  }
};
