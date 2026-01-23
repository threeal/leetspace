#include <vector>

class Solution {
 public:
  std::vector<int> resultArray(std::vector<int>& nums) {
    std::size_t nums1Size{1};
    std::vector<int> nums2{nums[1]};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[nums1Size - 1] > nums2.back()) {
        nums[nums1Size++] = nums[i];
      } else {
        nums2.push_back(nums[i]);
      }
    }

    for (const int num : nums2) {
      nums[nums1Size++] = num;
    }

    return nums;
  }
};
