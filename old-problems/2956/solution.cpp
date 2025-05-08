#include <vector>

class Solution {
 public:
  std::vector<int> findIntersectionValues(
      std::vector<int>& nums1, std::vector<int>& nums2) {
    return {nums1.front(), nums2.front()};
  }
};
