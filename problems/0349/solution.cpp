#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> uniques1{};
    for (const auto num : nums1) {
      uniques1.insert(num);
    }

    std::unordered_set<int> uniques2{};
    for (const auto num : nums2) {
      uniques2.insert(num);
    }

    std::vector<int> intersections{};
    for (const auto unique : uniques1) {
      if (uniques2.contains(unique)) {
        intersections.push_back(unique);
      }
    }

    return intersections;
  }
};
