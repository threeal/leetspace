#include <algorithm>
#include <vector>

class Solution {
 public:
  int minMoves2(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int moves{0};
    const std::size_t mid{nums.size() / 2};

    for (std::size_t i{0}; i < mid; ++i) {
      moves += nums[mid] - nums[i];
    }

    for (std::size_t i{mid + 1}; i < nums.size(); ++i) {
      moves += nums[i] - nums[mid];
    }

    return moves;
  }
};
