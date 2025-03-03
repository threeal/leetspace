#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> mergeArrays(
      std::vector<std::vector<int>>& nums1,
      std::vector<std::vector<int>>& nums2) {
    std::vector<std::vector<int>> output{};

    std::size_t i1{0}, i2{0};
    while (i1 < nums1.size() && i2 < nums2.size()) {
      if (nums1[i1][0] == nums2[i2][0]) {
        output.push_back({nums1[i1][0], nums1[i1][1] + nums2[i2][1]});
        ++i1, ++i2;
      } else {
        if (nums1[i1][0] < nums2[i2][0]) {
          output.push_back(nums1[i1++]);
        } else {
          output.push_back(nums2[i2++]);
        }
      }
    }

    while (i1 < nums1.size()) output.push_back(nums1[i1++]);
    while (i2 < nums2.size()) output.push_back(nums2[i2++]);

    return output;
  }
};
