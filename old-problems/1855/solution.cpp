#include <vector>

class Solution {
 public:
  int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::size_t i{0}, j{1};
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] > nums2[j]) ++i;
      ++j;
    }
    return j - i - 1;
  }
};
