#include <numeric>
#include <vector>

class Solution {
 public:
  int countMaxOrSubsets(std::vector<int>& nums) {
    const auto max = std::accumulate(
        nums.begin(), nums.end(), 0, std::bit_or<int>());

    return countSubsets(nums, 0, max, 0);
  }

 private:
  static int countSubsets(
      std::vector<int>& nums, std::size_t i, int max, int prev) {
    if (i == nums.size()) return 0;
    return ((prev | nums[i]) == max ? 1 : 0) +
        countSubsets(nums, i + 1, max, prev | nums[i]) +
        countSubsets(nums, i + 1, max, prev);
  }
};
