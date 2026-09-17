#include <vector>

class Solution {
 public:
  int minSumOfLengths(std::vector<int>& arr, int target) {
    return static_cast<int>(arr.size()) + target;
  }
};
