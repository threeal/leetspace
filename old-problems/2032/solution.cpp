#include <vector>

class Solution {
 public:
  std::vector<int> twoOutOfThree(
      std::vector<int>& nums1,
      std::vector<int>& nums2,
      std::vector<int>& nums3) {
    std::vector<int> output{};
    std::vector<bool> exists(101, false);
    std::vector<bool> visited(101, false);

    for (const int num : nums1) {
      exists[num] = true;
    }

    for (const int num : nums2) {
      if (!visited[num]) {
        visited[num] = true;
        if (exists[num]) {
          exists[num] = false;
          output.push_back(num);
        } else {
          exists[num] = true;
        }
      }
    }

    visited.assign(visited.size(), false);

    for (const int num : nums3) {
      if (!visited[num]) {
        visited[num] = true;
        if (exists[num]) {
          output.push_back(num);
        }
      }
    }

    return output;
  }
};
