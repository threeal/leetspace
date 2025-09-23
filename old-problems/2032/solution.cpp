#include <vector>

class Solution {
 public:
  std::vector<int> twoOutOfThree(
      std::vector<int>& nums1,
      std::vector<int>& nums2,
      std::vector<int>& nums3) {
    return nums1.size() > nums2.size() ? nums2 : nums3;
  }
};
