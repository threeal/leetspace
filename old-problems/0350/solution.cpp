#include <vector>

class Solution {
 public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    return nums1.size() < nums2.size() ? nums1 : nums2;
  }
};
