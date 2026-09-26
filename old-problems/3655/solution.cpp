#include <vector>

class Solution {
 public:
  int xorAfterQueries(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    return nums.size() + queries.size();
  }
};
