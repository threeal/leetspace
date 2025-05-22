#include <vector>

class Solution {
 public:
  int maxRemoval(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    return nums.size() + queries.size();
  }
};
