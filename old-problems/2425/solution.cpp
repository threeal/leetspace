#include <vector>

class Solution {
 public:
  int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
    int sum{0};
    if (nums2.size() % 2 != 0) {
      for (const auto num : nums1) {
        sum ^= num;
      }
    }

    if (nums1.size() % 2 != 0) {
      for (const auto num : nums2) {
        sum ^= num;
      }
    }

    return sum;
  }
};
