#include <vector>

class Solution {
 public:
  bool isTrionic(std::vector<int>& nums) {
    if (nums[1] <= nums[0]) return false;

    std::size_t i{2};
    while (i < nums.size() && nums[i - 1] < nums[i]) ++i;
    if (i == nums.size() || nums[i - 1] == nums[i]) return false;

    while (i < nums.size() && nums[i - 1] > nums[i]) ++i;
    if (i == nums.size() || nums[i - 1] == nums[i]) return false;

    while (i < nums.size() && nums[i - 1] < nums[i]) ++i;
    return i == nums.size();
  }
};
