#include <vector>

class Solution {
 public:
  int minMoves(std::vector<int>& nums, int limit) {
    const int limit2{2 * limit};
    std::vector<int> prefixMoves(limit2 + 2, 0);

    prefixMoves[2] += nums.size();
    for (std::size_t l{0}, r{nums.size() - 1}; l < r; ++l, --r) {
      --prefixMoves[std::min(nums[l], nums[r]) + 1];
      --prefixMoves[nums[l] + nums[r]];
      ++prefixMoves[nums[l] + nums[r] + 1];
      ++prefixMoves[std::max(nums[l], nums[r]) + limit + 1];
    }

    int moves{prefixMoves[2]}, minMoves{moves};
    for (int i{3}; i <= limit2; ++i) {
      moves += prefixMoves[i];
      if (moves < minMoves) minMoves = moves;
    }

    return minMoves;
  }
};
