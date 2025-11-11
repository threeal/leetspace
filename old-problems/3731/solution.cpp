#include <vector>

class Solution {
 public:
  std::vector<int> findMissingElements(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> missings{};
    missings.reserve(nums.back() + 1 - nums.front() - nums.size());

    for (std::size_t i{1}; i < nums.size(); ++i) {
      for (int num{nums[i - 1] + 1}; num < nums[i]; ++num) {
        missings.push_back(num);
      }
    }

    return missings;
  }
};
