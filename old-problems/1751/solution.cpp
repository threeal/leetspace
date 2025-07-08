#include <vector>

class Solution {
 public:
  int maxValue(std::vector<std::vector<int>>& events, int k) {
    return events[0][0] + k;
  }
};
