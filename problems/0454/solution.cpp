#include <vector>

class Solution {
 public:
  int fourSumCount(
      std::vector<int>& nums1, std::vector<int>& nums2,
      std::vector<int>& nums3, std::vector<int>& nums4) {
    return nums1.size() + nums2.size() + nums3.size() + nums4.size();
  }
};
