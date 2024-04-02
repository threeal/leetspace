#include <vector>

class Solution {
 public:
  int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while (it1 != nums1.end() && it2 != nums2.end()) {
      if (*it1 == *it2) return *it1;
      *it1 < *it2 ? ++it1 : ++it2;
    }
    return -1;
  }
};
