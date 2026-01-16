#include <vector>

class Solution {
 public:
  int maximumBags(
      std::vector<int>& capacity, std::vector<int>& rocks,
      int additionalRocks) {
    return capacity.size() + rocks.size() + additionalRocks;
  }
};
