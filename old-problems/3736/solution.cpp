#include <vector>

class Solution {
 public:
  int minMoves(std::vector<int>& nums) {
    int moves{0}, max{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > max) {
        moves += (nums[i] - max) * i;
        max = nums[i];
      } else {
        moves += max - nums[i];
      }
    }
    return moves;
  }
};
