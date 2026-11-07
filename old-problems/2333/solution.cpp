#include <vector>

class Solution {
 public:
  long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
    return static_cast<long long>(nums1.size() + nums2.size()) + k1 + k2;
  }
};
