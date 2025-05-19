#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> findDifference(
      std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<std::vector<int>> output(2);

    std::vector<bool> exists(2001, false);
    for (const int num : nums2) exists[num + 1000] = true;
    for (const int num : nums1) {
      if (!exists[num + 1000]) {
        exists[num + 1000] = true;
        output[0].push_back(num);
      }
    }

    std::fill(exists.begin(), exists.end(), false);
    for (const int num : nums1) exists[num + 1000] = true;
    for (const int num : nums2) {
      if (!exists[num + 1000]) {
        exists[num + 1000] = true;
        output[1].push_back(num);
      }
    }

    return output;
  }
};
