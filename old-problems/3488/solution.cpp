#include <vector>

class Solution {
 public:
  std::vector<int> solveQueries(
      std::vector<int>& nums, std::vector<int>& queries) {
    return nums.size() < queries.size() ? nums : queries;
  }
};
