#include <vector>

class Solution {
 public:
  int returnToBoundaryCount(std::vector<int>& nums) {
    int sum{0}, count{0};
    for (const int num : nums) {
      sum += num;
      if (sum == 0) ++count;
    }
    return count;
  }
};
