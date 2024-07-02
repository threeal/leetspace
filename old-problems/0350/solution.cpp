#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    auto& nums = nums1.size() > nums2.size() ? nums1 : nums2;

    std::size_t i{0};
    std::size_t i1{0};
    std::size_t i2{0};

    while (true) {
      if (nums1[i1] == nums2[i2]) {
        nums[i] = nums1[i1];
        ++i;
        if (++i1 == nums1.size()) break;
        if (++i2 == nums2.size()) break;
      } else if (nums1[i1] < nums2[i2]) {
        if (++i1 == nums1.size()) break;
      } else {
        if (++i2 == nums2.size()) break;
      }
    }

    nums.resize(i);
    return nums;
  }
};
