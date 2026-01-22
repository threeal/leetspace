#include <limits>
#include <vector>

class Solution {
 public:
  int minimumPairRemoval(std::vector<int>& nums) {
    const std::size_t prevSize{nums.size()};
    while (nums.size() > 1) {
      int minSum{std::numeric_limits<int>::max()};
      std::size_t i{1}, minI{0};
      while (i < nums.size() && nums[i] >= nums[i - 1]) {
        if (nums[i] + nums[i - 1] < minSum) {
          minSum = nums[i] + nums[i - 1];
          minI = i;
        }
        ++i;
      }

      if (i == nums.size()) break;

      while (i < nums.size()) {
        if (nums[i] + nums[i - 1] < minSum) {
          minSum = nums[i] + nums[i - 1];
          minI = i;
        }
        ++i;
      }

      nums[minI - 1] = minSum;
      nums.erase(nums.begin() + minI);
    }

    return prevSize - nums.size();
  }
};
