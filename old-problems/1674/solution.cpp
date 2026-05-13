#include <vector>

class Solution {
 public:
  int minMoves(std::vector<int>& nums, int limit) {
    return nums.size() + limit;
  }
};
