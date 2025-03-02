#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> mergeArrays(
      std::vector<std::vector<int>>& nums1,
      std::vector<std::vector<int>>& nums2) {
    return nums1.size() >= nums2.size() ? nums1 : nums2;
  }
};
