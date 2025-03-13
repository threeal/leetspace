#include <vector>

class Solution {
 public:
  int minZeroArray(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    return nums.size() + queries.size();
  }
};
