#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    std::vector<int> plans(nums.size(), -1);
    return planRob(plans, nums, 0);
  }

  int planRob(std::vector<int>& plans, std::vector<int>& nums, std::size_t i) {
    if (i >= nums.size()) return 0;

    if (plans[i] < 0) {
      plans[i] = std::max(
          nums[i] + planRob(plans, nums, i + 2),
          planRob(plans, nums, i + 1));
    }

    return plans[i];
  }
};
