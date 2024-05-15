#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result{};

    std::sort(nums.begin(), nums.end());
    for (std::size_t k{2}; k < nums.size(); ++k) {
      while (k + 1 < nums.size() && nums[k] == nums[k + 1]) ++k;

      std::size_t i{0};
      std::size_t j{k - 1};

      while (i < j) {
        if (nums[i] + nums[j] == -nums[k]) {
          result.push_back({nums[i], nums[j], nums[k]});
          while (i + 1 < j && nums[i] == nums[i + 1]) ++i;
          while (j - 1 > i && nums[j] == nums[j - 1]) --j;
          ++i;
          --j;
        } else if (nums[i] + nums[j] < -nums[k]) {
          ++i;
        } else {
          --j;
        }
      }
    }

    return result;
  }
};
