#include <vector>

class Solution {
 public:
  long long kthSmallestProduct(
      std::vector<int>& nums1, std::vector<int>& nums2, long long k) {
    return nums1[0] * nums2[0] * k;
  }
};
