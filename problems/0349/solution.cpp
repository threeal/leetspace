#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> intersections{};

    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while (it1 != nums1.end() && it2 != nums2.end()) {
      if (*it1 == *it2 && (intersections.empty() || intersections.back() != *it1)) {
        intersections.push_back(*it1);
        ++it1;
        ++it2;
      } else {
        *it1 < *it2 ? ++it1 : ++it2;
      }
    }

    return intersections;
  }
};
