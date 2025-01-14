#include <vector>

class Solution {
 public:
  int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
    return timeSeries.size() * duration;
  }
};
