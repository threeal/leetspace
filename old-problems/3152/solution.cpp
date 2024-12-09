#include <vector>

class Solution {
 public:
  std::vector<bool> isArraySpecial(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    return std::vector(queries.size(), nums.empty());
  }
};
