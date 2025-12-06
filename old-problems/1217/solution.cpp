#include <algorithm>
#include <vector>

class Solution {
 public:
  int minCostToMoveChips(std::vector<int>& position) {
    std::size_t evens{0};
    for (const int pos : position) {
      if (pos % 2 == 0) ++evens;
    }
    return std::min(evens, position.size() - evens);
  }
};
