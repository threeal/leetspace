#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> findIntersectionValues(
      std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    std::size_t i1{0}, i2{0};
    int count1{0}, count2{0};
    while (i1 < nums1.size() && i2 < nums2.size()) {
      if (nums1[i1] >= nums2[i2]) {
        while (i2 < nums2.size() && nums2[i2] < nums1[i1]) ++i2;
        if (i2 == nums2.size()) break;
      } else {
        while (i1 < nums1.size() && nums1[i1] < nums2[i2]) ++i1;
        if (i1 == nums1.size()) break;
      }

      if (nums1[i1] == nums2[i2]) {
        const int num{nums1[i1]};
        while (i1 < nums1.size() && nums1[i1] == num) ++i1, ++count1;
        while (i2 < nums2.size() && nums2[i2] == num) ++i2, ++count2;
      }
    }

    return {count1, count2};
  }
};
