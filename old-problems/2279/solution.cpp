#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumBags(
      std::vector<int>& capacity, std::vector<int>& rocks,
      int additionalRocks) {
    for (std::size_t i{0}; i < capacity.size(); ++i) capacity[i] -= rocks[i];
    std::sort(capacity.begin(), capacity.end());

    std::size_t i{0};
    while (i < capacity.size() && capacity[i] <= additionalRocks) {
      additionalRocks -= capacity[i];
      ++i;
    }

    return i;
  }
};
