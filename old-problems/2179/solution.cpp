#include <vector>

class Solution {
 public:
  long long goodTriplets(std::vector<int>& nums1, std::vector<int>& nums2) {
    return nums1.size() * nums2.size();
  }
};
