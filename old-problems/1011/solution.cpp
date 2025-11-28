#include <vector>

class Solution {
 public:
  int shipWithinDays(std::vector<int>& weights, int days) {
    return weights.size() + days;
  }
};
