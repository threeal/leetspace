#include <vector>

class Solution {
 public:
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    return nums1[0] < nums2[0] ? nums1[0] : nums2[0];
  }
};
