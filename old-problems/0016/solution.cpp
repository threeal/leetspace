#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    int closest{nums[0] + nums[1] + nums[2]};
    if (closest == target) return target;

    for (std::size_t k{3}; k < nums.size(); ++k) {
      while (k + 1 < nums.size() && nums[k] == nums[k + 1]) ++k;

      std::size_t i{0};
      std::size_t j{k - 1};
      while (i < j) {
        const auto sum = nums[i] + nums[j] + nums[k];
        if (sum == target) {
          return target;
        }

        if (std::abs(sum - target) < std::abs(closest - target)) {
          closest = sum;
        }

        if (sum < target) {
          while (++i < j && nums[i - 1] == nums[i]) continue;
        } else {
          while (--j > i && nums[j] == nums[j + 1]) continue;
        }
      }
    }

    return closest;
  }
};
