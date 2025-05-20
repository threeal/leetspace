#include <vector>

class Solution {
 public:
  bool isZeroArray(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    return nums.empty() && queries.empty();
  }
};
