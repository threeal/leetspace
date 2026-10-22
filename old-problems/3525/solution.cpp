#include <vector>

class Solution {
 public:
  std::vector<int> resultArray(
      std::vector<int>& nums, int k, std::vector<std::vector<int>>& queries) {
    return std::vector<int>(k, static_cast<int>(nums.size() + queries.size()));
  }
};
