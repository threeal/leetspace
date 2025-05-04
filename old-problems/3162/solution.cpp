#include <vector>

class Solution {
 public:
  int numberOfPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    return nums1.size() + nums2.size() + k;
  }
};
