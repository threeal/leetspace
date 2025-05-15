#include <vector>

class Solution {
 public:
  int addedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
    int min1{nums1[0]}, min2{nums2[0]};
    for (std::size_t i{0}; i < nums1.size(); ++i) {
      if (nums1[i] < min1) min1 = nums1[i];
      if (nums2[i] < min2) min2 = nums2[i];
    }
    return min2 - min1;
  }
};
