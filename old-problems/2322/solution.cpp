#include <vector>

class Solution {
 public:
  int minimumScore(std::vector<int> &nums, std::vector<std::vector<int>> &edges) {
    return nums[0] + edges[0][0];
  }
};
